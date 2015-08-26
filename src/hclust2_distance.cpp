/* ************************************************************************* *
 *   This file is part of the `DataStructures` package.                      *
 *                                                                           *
 *   Copyright 2015 Maciej Bartoszuk, Anna Cena, Marek Gagolewski,           *
 *                                                                           *
 *   'DataStructures' is free software: you can redistribute it and/or       *
 *   modify it under the terms of the GNU Lesser General Public License      *
 *   as published by the Free Software Foundation, either version 3          *
 *   of the License, or (at your option) any later version.                  *
 *                                                                           *
 *   'DataStructures' is distributed in the hope that it will be useful,     *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the            *
 *   GNU Lesser General Public License for more details.                     *
 *                                                                           *
 *   You should have received a copy of the GNU Lesser General Public        *
 *   License along with 'DataStructures'.                                    *
 *   If not, see <http://www.gnu.org/licenses/>.                             *
 * ************************************************************************* */

#include <algorithm>
#include "hclust2_distance.h"
using namespace DataStructures;


Distance::Distance(size_t n) :
#ifdef HASHMAP_ENABLED
   hashmap(std::vector< std::unordered_map<size_t, double> >(n)),
#endif
   stats(DistanceStats(n)),
   n(n)
{
#ifdef HASHMAP_ENABLED
   MESSAGE_1("Warning: HASHMAP_ENABLED is defined in hclust2_distance.h\n");
#endif
#ifdef GENERATE_STATS
   MESSAGE_1("Warning: GENERATE_STATS is defined in hclust2_distance.h\n");
#endif
}


Distance::~Distance()
{
// #if VERBOSE > 5
//    Rprintf("[%010.3f] destroying distance object (base)\n", clock()/(float)CLOCKS_PER_SEC);
// #endif
}


#ifdef HASHMAP_ENABLED
double Distance::operator()(size_t v1, size_t v2)
{
   if (v1 == v2) return 0.0;
   if (v1 > v2) std::swap(v1, v2);

#ifdef GENERATE_STATS
#ifdef _OPENMP
#pragma omp atomic
#endif
      ++stats.distCallCount;
#endif

   // this is thread unsafe, but we use it only for testing:
   auto got = hashmap[v1].find(v2);
   if ( got == hashmap[v1].end() )
   {
#ifdef GENERATE_STATS
#ifdef _OPENMP
#pragma omp atomic
#endif
      ++stats.hashmapMiss;
#endif
      double d = compute(v1, v2);
      hashmap[v1].emplace(v2, d);
      return d;
   }
   else
   {
#ifdef GENERATE_STATS
#ifdef _OPENMP
#pragma omp atomic
#endif
      ++stats.hashmapHit;
#endif
      return got->second;
   }
}
#endif


Distance* Distance::createDistance(Rcpp::RObject distance, Rcpp::RObject objects)
{
   if (Rf_isVectorList(objects) && Rf_isFunction(distance))
   {
      Rcpp::Function distance2(distance);
      Rcpp::List objects2(objects);
      return (DataStructures::Distance*)
         new DataStructures::GenericRDistance(
            distance2,
            std::vector<Rcpp::RObject>(objects2.begin(), objects2.end())
         );
   }
   else if (Rf_isNumeric(distance) && Rf_isObject(distance) && !strcmp(distance.attr("class"), "dist") && Rf_isNull(objects))
   {
      return (DataStructures::Distance*)
            new DataStructures::DistObjectDistance(
               (Rcpp::NumericVector)distance
            );
   }
   else if (Rf_isString(objects) && (Rf_isNull(distance) || Rf_isString(distance)))
   {
      Rcpp::CharacterVector objects2(objects);
      Rcpp::CharacterVector distance2 =
         ((Rf_isNull(distance))?Rcpp::CharacterVector("levenshtein"):Rcpp::CharacterVector(distance));

      const char* distance3 = CHAR(STRING_ELT((SEXP)distance2, 0));
      if (!strcmp(distance3, "levenshtein")) {
         return (DataStructures::Distance*)
            new DataStructures::LevenshteinDistance(
               objects2
            );
      }
      else if (!strcmp(distance3, "dinu")) {
         return (DataStructures::Distance*)
            new DataStructures::DinuDistance(
               objects2
            );
      }
      else {
         Rcpp::stop("`distance` should be one of: \"levenshtein\" (default), \"dinu\"");
      }
   }
   else if (Rf_isMatrix(objects) && Rf_isNumeric(objects) && (Rf_isNull(distance) || Rf_isString(distance)))
   {
      Rcpp::NumericMatrix objects2(objects);
      Rcpp::CharacterVector distance2 =
         ((Rf_isNull(distance))?Rcpp::CharacterVector("euclidean"):Rcpp::CharacterVector(distance));

      const char* distance3 = CHAR(STRING_ELT((SEXP)distance2, 0));
      if (!strcmp(distance3, "euclidean")) {
         return (DataStructures::Distance*)
            new DataStructures::EuclideanDistance(
               objects2
            );
      }
      else if (!strcmp(distance3, "manhattan")) {
         return (DataStructures::Distance*)
            new DataStructures::ManhattanDistance(
               objects2
            );
      }
      else if (!strcmp(distance3, "maximum")) {
         return (DataStructures::Distance*)
            new DataStructures::MaximumDistance(
               objects2
            );
      }
      else if (!strcmp(distance3, "hamming")) {
         return (DataStructures::Distance*)
            new DataStructures::HammingDistance(
               objects2
            );
      }
      else {
         Rcpp::stop("`distance` should be one of: \"euclidean\" (default), \"manhattan\", \"maximum\", \"hamming\"");
      }
   }
   else {
      Rcpp::stop("incorrect input data");
   }
   return NULL;
}



GenericMatrixDistance::GenericMatrixDistance(const Rcpp::NumericMatrix& points) :
      Distance(points.nrow()),
      items(REAL((SEXP)points)), m(points.ncol())  {
   // act on a transposed matrix to avoid many L1/L... cache misses
   items = new double[m*n];
   const double* items2 = REAL((SEXP)points);
   double* items_ptr = items;
   for (size_t i=0; i<n; ++i) {
      for (size_t j=0; j<m; ++j) {
         if (Rcpp::NumericVector::is_na(items2[j*n+i]))
            Rcpp::stop("missing values in input objects are not allowed");
         *(items_ptr++) = items2[j*n+i];
      }
   }
}


double EuclideanDistance::compute(size_t v1, size_t v2)
{
   if (v1 == v2) return 0.0;
   double d = 0.0;
   for (size_t i=0; i<m; ++i)
      d += (items[v1*m+i]-items[v2*m+i])*(items[v1*m+i]-items[v2*m+i]);
   return sqrt(d);

// this is not faster:
//    double d = sqobs[v1]+sqobs[v2]; // already multiplied by 0.5
//    // sum((x-y)^2) == 2*(sum(x^2)/2 + sum(y^2)/2 - sum(x*y))
//    const double* items1_ptr = items+v1*m;
//    const double* items2_ptr = items+v2*m;
//    for (size_t i=0; i<m; ++i)
//       d -= (*(items1_ptr++))*(*(items2_ptr++));
//    return sqrt(2.0*d);
}


double ManhattanDistance::compute(size_t v1, size_t v2)
{
   if (v1 == v2) return 0.0;
   double d = 0.0;
   for (size_t i=0; i<m; ++i)
      d += std::abs(items[v1*m+i]-items[v2*m+i]);
   return d;
}


double MaximumDistance::compute(size_t v1, size_t v2)
{
   if (v1 == v2) return 0.0;
   double d = 0.0;
   for (size_t i=0; i<m; ++i) {
      double d2 = std::abs(items[v1*m+i]-items[v2*m+i]);
      if (d2 > d) d = d2;
   }
   return d;
}

double HammingDistance::compute(size_t v1, size_t v2)
{
   if (v1 == v2) return 0.0;
   double d = 0.0;
   for (size_t i=0; i<m; ++i) {
      if (items[v1*m+i] != items[v2*m+i]) d += 1.0;
   }
   return d;
}


double GenericRDistance::compute(size_t v1, size_t v2)
{
   if (v1 == v2) return 0.0;
   return ((Rcpp::NumericVector)distfun(items[v1], items[v2]))[0];
}


StringDistance::StringDistance(const Rcpp::CharacterVector& strings) :
      Distance(strings.size()),
      robj((SEXP)strings) {
   R_PreserveObject(robj);
   items = new const char*[n];
   lengths = new size_t[n];

   // TO DO: NA HANDLING
   for (size_t i=0; i<n; ++i) {
      SEXP cur = STRING_ELT(robj, i);
      if (cur == NA_STRING)
         Rcpp::stop("missing values in input objects are not allowed");
      lengths[i] = LENGTH(cur);
      items[i] = CHAR(cur);
   }
}


StringDistance::~StringDistance() {
   delete [] items;
   delete [] lengths;
   R_ReleaseObject(robj);
}


double DistObjectDistance::compute(size_t v1, size_t v2)
{
   if (v1 == v2) return 0.0;

   size_t i;
   if (v1 < v2)
      i = n*v1-((v1+1)*(v1))/2+v2-v1-1;
   else
      i = n*v2-((v2+1)*(v2))/2+v1-v2-1;

   return items[i];
}


double LevenshteinDistance::compute(size_t v1, size_t v2)
{
   const char* s1 = items[v1];
   const char* s2 = items[v2];
   size_t n1 = lengths[v1];
   size_t n2 = lengths[v2];
   if (n1 < n2) {
      std::swap(s1, s2); // pointer swap
      std::swap(n1, n2);
   }

#ifdef _OPENMP
   // to be thread-safe, we have to allocate these 2 arrays each time...
   size_t* v_cur = new size_t[n2+1];
   size_t* v_last = new size_t[n2+1];
#endif

   // n2 <= n1
   for (size_t j=0; j<=n2; ++j) v_cur[j] = j;

   for (size_t i=1; i<=n1; ++i) {
      std::swap(v_last, v_cur); // pointer swap
      v_cur[0] = i;
      for (size_t j=1; j<=n2; ++j) {
         if (s1[i-1] == s2[j-1])
            v_cur[j] = v_last[j-1];
         else
            v_cur[j] = std::min(std::min(
               v_last[j-1]+1,
               v_cur[j-1]+1),
               v_last[j]+1);
      }
   }

   double ret = (double) v_cur[n2];
#ifdef _OPENMP
   delete [] v_cur;
   delete [] v_last;
#endif
   return ret;
}


double DinuDistance::compute(size_t v1, size_t v2)
{
   const char* x = items[v1];
   const char* y = items[v2];
   const size_t* ox = ranks[v1].data();
   const size_t* oy = ranks[v2].data();
   size_t nx = lengths[v1];
   size_t ny = lengths[v2];

   double d = 0.0;
   size_t ix = 0, iy = 0;
   while (ix < nx && iy < ny) {
      if (x[ox[ix]] == y[oy[iy]])
         d += std::abs((ox[ix++]+1.0) - (oy[iy++]+1.0));
      else if (x[ox[ix]] < y[oy[iy]])
         d += std::abs((ox[ix++]+1.0) - 0.0);
      else
         d += std::abs(0.0 - (oy[iy++]+1.0));
   }
   while (ix < nx) d += std::abs((ox[ix++]+1.0) - 0.0);
   while (iy < ny) d += std::abs(0.0 - (oy[iy++]+1.0));

   return d;
}

