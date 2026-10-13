#include "pch.h"
#include "Header.h"
// sqrt_test.cpp
#include <gtest/gtest.h>



TEST(Question_1, Test1) {
	std::string str = "mytttiiifsdjjojsadhsadunefwefwefwefdshjyiohdgwrg";
	int k = 4;
	std::string ans = "ytttisdjjojsadhsadunefwefwefwefdshjyiohdgwrg";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}

TEST(Question_1, Test2) {
	std::string str = "codingisnofununtilyoudodsa";
	int k = 8;
	std::string ans = "sofununtilyoudodsa";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}

TEST(Question_1, Test3) {
	std::string str = "rebmasitohsui";
	int k = 3;
	std::string ans = "rmsitohsui";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}

TEST(Question_1, Test4) {
	std::string str = "farigballdamhadbj";
	int k = 5;
	std::string ans = "rilldamhadbj";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}

TEST(Question_1, Test5) {
	std::string str = "maajyutrrabcde";
	int k = 2;
	std::string ans = "mjyutrrabcde";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}
TEST(Question_1, Test6) {
	std::string str = "bayesianmodelingandcomputationinpython";
	int k = 11;
	std::string ans = "ysongandcomputationinpython";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}
TEST(Question_1, Test7) {
	std::string str = "thetestcasesarerunningveryfastlyanssmoothlyifnoerror";
	int k = 25;
	std::string ans = "yfastlyanssmoothlyifnoerror";
	EXPECT_EQ(ans, largestString(str, k)); // This expectation will fail
}


// Test case Question-2
TEST(Question_2, Test1) {
	std::string str = "45";
	int k = 1;
	std::string ans = "4";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test2) {
	std::string str = "96";
	int k = 1;
	std::string ans = "6";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test3) {
	std::string str = "6789";
	int k = 0;
	std::string ans = "6789";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test4) {
	std::string str = "6";
	int k = 0;
	std::string ans = "6";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test5) {
	std::string str = "287948768";
	int k = 0;
	std::string ans = "287948768";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test6) {
	std::string str = "53980517";
	int k = 2;
	std::string ans = "380517";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test7) {
	std::string str = "37594852632";
	int k = 10;
	std::string ans = "2";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test8) {
	std::string str = "739717549062896";
	int k = 1;
	std::string ans = "39717549062896";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test9) {
	std::string str = "2233300000000000000";
	int k = 3;
	std::string ans = "2200000000000000";
	EXPECT_EQ(ans, solve(str, k));
}

TEST(Question_2, Test10) {
	std::string str = "1766739498453158327826647316936982938316534805172218962557053186925224732";
	int k = 2;
	std::string ans = "16639498453158327826647316936982938316534805172218962557053186925224732";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test11) {
	std::string str = "464038665066592229991395446868568141659015313318498114800229294263538051662670061878";
	int k = 28;
	std::string ans = "13445141659015313318498114800229294263538051662670061878";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test12) {
	std::string str = "2910325986297865201398145278756";
	int k = 27;
	std::string ans = "1001";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test13) {
	std::string str = "930879762870164";
	int k = 10;
	std::string ans = "20164";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test14) {
	std::string str = "930879762870164";
	int k = 7;
	std::string ans = "30270164";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test15) {
	std::string str = "98270191379642239801000";
	int k = 17;
	std::string ans = "101000";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test16) {
	std::string str = "9130879762870164";
	int k = 6;
	std::string ans = "1062870164";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test17) {
	std::string str = "33116942136944382547201525926838264018237352941636816111378464606794530121508659452194461702803322402854098114153742590606099186000514893217135846183700650976039210043487842082000525870622297576330646562331537278636513705018";
	int k = 17;
	std::string ans = "111201525926838264018237352941636816111378464606794530121508659452194461702803322402854098114153742590606099186000514893217135846183700650976039210043487842082000525870622297576330646562331537278636513705018";
	EXPECT_EQ(ans, solve(str, k));
}
TEST(Question_2, Test18) {
	std::string str = "8560939253348536196097610320187655857528117487129453131962830794082946501188358451343512561411685569268013313171955315110763501239488549781929767578499750340225342234289525902005099796222388377200380997905418005791340702397993768554375426094217353290278326847636140041461835336838457184905846892005862893580993480260591388763416188174936074266473244346945282940922168669414760924824487825346501474490213651427769722935532486778217563397546";
	int k = 45;
	std::string ans = "1000111111962830794082946501188358451343512561411685569268013313171955315110763501239488549781929767578499750340225342234289525902005099796222388377200380997905418005791340702397993768554375426094217353290278326847636140041461835336838457184905846892005862893580993480260591388763416188174936074266473244346945282940922168669414760924824487825346501474490213651427769722935532486778217563397546";
	EXPECT_EQ(ans, solve(str, k));
}


// Test case Question-3
TEST(Question_3, Test1) {
	int arr[5] = { 1,2,3,4,5 };
	int arr2[1] = { 5 };
	int k = 1;
	int size = 5;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}

TEST(Question_3, Test2) {
	int arr[10] = { 3, -1, -2, 4, 6, -2, 2, 4, 6, -1 };
	int arr2[5] = { 6, -2 , 2 , 4 , 6 };
	int k = 5;
	int size = 10;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}

TEST(Question_3, Test3) {
	int arr[5] = { 0, 0 , 0 , 0 , 0 };
	int arr2[5] = { 0, 0 , 0 , 0 , 0 };
	int k = 5;
	int size = 5;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}

TEST(Question_3, Test4) {
	int arr[5] = { -5,-1,-1,-1,-1 };
	int arr2[2] = { -1, -1 };
	int k = 2;
	int size = 5;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}

TEST(Question_3, Test5) {
	int arr[8] = { 10, -5, 7, -3, 5, 1, -2, -6 };
	int arr2[5] = { 7, -3, 5, 1 };
	int k = 4;
	int size = 8;
	int* result = maxSubsequence(arr, size, k);
	for (int i = 0; i < k; i++)
		EXPECT_EQ(arr2[i], result[i]);
}


