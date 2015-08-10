// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// hclust3
SEXP hclust3(SEXP const method_, SEXP const metric_, SEXP X_, SEXP members_, SEXP p_);
RcppExport SEXP DataStructures_hclust3(SEXP method_SEXP, SEXP metric_SEXP, SEXP X_SEXP, SEXP members_SEXP, SEXP p_SEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP const >::type method_(method_SEXP);
    Rcpp::traits::input_parameter< SEXP const >::type metric_(metric_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type X_(X_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type members_(members_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type p_(p_SEXP);
    __result = Rcpp::wrap(hclust3(method_, metric_, X_, members_, p_));
    return __result;
END_RCPP
}
// hclust_gnat_single_test
void hclust_gnat_single_test(RObject distance, RObject objects, RObject control, int index, double R);
RcppExport SEXP DataStructures_hclust_gnat_single_test(SEXP distanceSEXP, SEXP objectsSEXP, SEXP controlSEXP, SEXP indexSEXP, SEXP RSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< RObject >::type distance(distanceSEXP);
    Rcpp::traits::input_parameter< RObject >::type objects(objectsSEXP);
    Rcpp::traits::input_parameter< RObject >::type control(controlSEXP);
    Rcpp::traits::input_parameter< int >::type index(indexSEXP);
    Rcpp::traits::input_parameter< double >::type R(RSEXP);
    hclust_gnat_single_test(distance, objects, control, index, R);
    return R_NilValue;
END_RCPP
}
// hclust_gnat_single
RObject hclust_gnat_single(RObject distance, RObject objects, RObject control);
RcppExport SEXP DataStructures_hclust_gnat_single(SEXP distanceSEXP, SEXP objectsSEXP, SEXP controlSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< RObject >::type distance(distanceSEXP);
    Rcpp::traits::input_parameter< RObject >::type objects(objectsSEXP);
    Rcpp::traits::input_parameter< RObject >::type control(controlSEXP);
    __result = Rcpp::wrap(hclust_gnat_single(distance, objects, control));
    return __result;
END_RCPP
}
// generateMergeMatrix
NumericMatrix generateMergeMatrix(NumericMatrix x);
RcppExport SEXP DataStructures_generateMergeMatrix(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    __result = Rcpp::wrap(generateMergeMatrix(x));
    return __result;
END_RCPP
}
// hclust2_complete
RObject hclust2_complete(RObject distance, RObject objects, int maxNumberOfElementsInLeaves);
RcppExport SEXP DataStructures_hclust2_complete(SEXP distanceSEXP, SEXP objectsSEXP, SEXP maxNumberOfElementsInLeavesSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< RObject >::type distance(distanceSEXP);
    Rcpp::traits::input_parameter< RObject >::type objects(objectsSEXP);
    Rcpp::traits::input_parameter< int >::type maxNumberOfElementsInLeaves(maxNumberOfElementsInLeavesSEXP);
    __result = Rcpp::wrap(hclust2_complete(distance, objects, maxNumberOfElementsInLeaves));
    return __result;
END_RCPP
}
// hclust2_medoid
RObject hclust2_medoid(RObject distance, RObject objects, RObject control);
RcppExport SEXP DataStructures_hclust2_medoid(SEXP distanceSEXP, SEXP objectsSEXP, SEXP controlSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< RObject >::type distance(distanceSEXP);
    Rcpp::traits::input_parameter< RObject >::type objects(objectsSEXP);
    Rcpp::traits::input_parameter< RObject >::type control(controlSEXP);
    __result = Rcpp::wrap(hclust2_medoid(distance, objects, control));
    return __result;
END_RCPP
}
// hclust2_single
RObject hclust2_single(RObject distance, RObject objects, RObject control);
RcppExport SEXP DataStructures_hclust2_single(SEXP distanceSEXP, SEXP objectsSEXP, SEXP controlSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< RObject >::type distance(distanceSEXP);
    Rcpp::traits::input_parameter< RObject >::type objects(objectsSEXP);
    Rcpp::traits::input_parameter< RObject >::type control(controlSEXP);
    __result = Rcpp::wrap(hclust2_single(distance, objects, control));
    return __result;
END_RCPP
}
// queue_as_list
List queue_as_list(SEXP queue);
RcppExport SEXP DataStructures_queue_as_list(SEXP queueSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type queue(queueSEXP);
    __result = Rcpp::wrap(queue_as_list(queue));
    return __result;
END_RCPP
}
// queue_create
SEXP queue_create();
RcppExport SEXP DataStructures_queue_create() {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    __result = Rcpp::wrap(queue_create());
    return __result;
END_RCPP
}
// queue_empty
bool queue_empty(SEXP queue);
RcppExport SEXP DataStructures_queue_empty(SEXP queueSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type queue(queueSEXP);
    __result = Rcpp::wrap(queue_empty(queue));
    return __result;
END_RCPP
}
// queue_push
void queue_push(SEXP queue, SEXP obj);
RcppExport SEXP DataStructures_queue_push(SEXP queueSEXP, SEXP objSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type queue(queueSEXP);
    Rcpp::traits::input_parameter< SEXP >::type obj(objSEXP);
    queue_push(queue, obj);
    return R_NilValue;
END_RCPP
}
// queue_pop
SEXP queue_pop(SEXP queue);
RcppExport SEXP DataStructures_queue_pop(SEXP queueSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type queue(queueSEXP);
    __result = Rcpp::wrap(queue_pop(queue));
    return __result;
END_RCPP
}
// stack_create
SEXP stack_create();
RcppExport SEXP DataStructures_stack_create() {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    __result = Rcpp::wrap(stack_create());
    return __result;
END_RCPP
}
// stack_as_list
List stack_as_list(SEXP stack);
RcppExport SEXP DataStructures_stack_as_list(SEXP stackSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type stack(stackSEXP);
    __result = Rcpp::wrap(stack_as_list(stack));
    return __result;
END_RCPP
}
// stack_empty
bool stack_empty(SEXP stack);
RcppExport SEXP DataStructures_stack_empty(SEXP stackSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type stack(stackSEXP);
    __result = Rcpp::wrap(stack_empty(stack));
    return __result;
END_RCPP
}
// stack_push
void stack_push(SEXP stack, SEXP obj);
RcppExport SEXP DataStructures_stack_push(SEXP stackSEXP, SEXP objSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type stack(stackSEXP);
    Rcpp::traits::input_parameter< SEXP >::type obj(objSEXP);
    stack_push(stack, obj);
    return R_NilValue;
END_RCPP
}
// stack_pop
SEXP stack_pop(SEXP stack);
RcppExport SEXP DataStructures_stack_pop(SEXP stackSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type stack(stackSEXP);
    __result = Rcpp::wrap(stack_pop(stack));
    return __result;
END_RCPP
}
// vector_as_list
List vector_as_list(SEXP vec);
RcppExport SEXP DataStructures_vector_as_list(SEXP vecSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type vec(vecSEXP);
    __result = Rcpp::wrap(vector_as_list(vec));
    return __result;
END_RCPP
}
// vector_create
SEXP vector_create(int n);
RcppExport SEXP DataStructures_vector_create(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    __result = Rcpp::wrap(vector_create(n));
    return __result;
END_RCPP
}
// vector_empty
bool vector_empty(SEXP vec);
RcppExport SEXP DataStructures_vector_empty(SEXP vecSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type vec(vecSEXP);
    __result = Rcpp::wrap(vector_empty(vec));
    return __result;
END_RCPP
}
// vector_size
int vector_size(SEXP vec);
RcppExport SEXP DataStructures_vector_size(SEXP vecSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type vec(vecSEXP);
    __result = Rcpp::wrap(vector_size(vec));
    return __result;
END_RCPP
}
// vector_front
RObject& vector_front(SEXP vec);
RcppExport SEXP DataStructures_vector_front(SEXP vecSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type vec(vecSEXP);
    __result = Rcpp::wrap(vector_front(vec));
    return __result;
END_RCPP
}
// vector_back
RObject& vector_back(SEXP vec);
RcppExport SEXP DataStructures_vector_back(SEXP vecSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type vec(vecSEXP);
    __result = Rcpp::wrap(vector_back(vec));
    return __result;
END_RCPP
}
// vector_push_back
void vector_push_back(SEXP vec, RObject obj);
RcppExport SEXP DataStructures_vector_push_back(SEXP vecSEXP, SEXP objSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type vec(vecSEXP);
    Rcpp::traits::input_parameter< RObject >::type obj(objSEXP);
    vector_push_back(vec, obj);
    return R_NilValue;
END_RCPP
}
// vector_pop_back
void vector_pop_back(SEXP vec);
RcppExport SEXP DataStructures_vector_pop_back(SEXP vecSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type vec(vecSEXP);
    vector_pop_back(vec);
    return R_NilValue;
END_RCPP
}
// vector_at
RObject& vector_at(SEXP vec, int i);
RcppExport SEXP DataStructures_vector_at(SEXP vecSEXP, SEXP iSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type vec(vecSEXP);
    Rcpp::traits::input_parameter< int >::type i(iSEXP);
    __result = Rcpp::wrap(vector_at(vec, i));
    return __result;
END_RCPP
}
// vector_set_at
void vector_set_at(SEXP vec, int i, RObject obj);
RcppExport SEXP DataStructures_vector_set_at(SEXP vecSEXP, SEXP iSEXP, SEXP objSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type vec(vecSEXP);
    Rcpp::traits::input_parameter< int >::type i(iSEXP);
    Rcpp::traits::input_parameter< RObject >::type obj(objSEXP);
    vector_set_at(vec, i, obj);
    return R_NilValue;
END_RCPP
}
