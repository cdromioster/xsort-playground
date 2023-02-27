#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(ProductionCode)
{
	RUN_TEST_CASE(ProductionCode, xsortFunction_10RandomElements);
	RUN_TEST_CASE(ProductionCode, xsortFunction_256RandomElements);
	RUN_TEST_CASE(ProductionCode, xsortFunction_1000RandomElements);
	RUN_TEST_CASE(ProductionCode, xsortFunction_10000RandomElements);
	RUN_TEST_CASE(ProductionCode, xsortFunction_50000RandomElements);
	RUN_TEST_CASE(ProductionCode, xsortFunction_50000AlreadySortredElements);
	RUN_TEST_CASE(ProductionCode, xsortFunction_50000ReverseSortedElements);
	RUN_TEST_CASE(ProductionCode, xsortFunction_50000FewUniqueElements);
}
