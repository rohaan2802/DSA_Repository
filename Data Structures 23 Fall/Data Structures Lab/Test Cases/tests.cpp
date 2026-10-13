#include "Array.cpp"
#include "BigInt.cpp"


#include <gtest/gtest.h>
// Q1: Array.cpp

TEST(Array, AssignmentAndEqual_A) {
    Array a1;
    ASSERT_EQ(true,!a1);// checks for NULL
    int arr[] = {1,2,3,4,5,6,7,8,9};
    Array a2(arr,9);
    a1 = a2;
    for(int i=0;i<9;i++){
        ASSERT_EQ(arr[i],a1[i]);
    }
}

TEST(Array, Addition_A) {
    int arr[] = {1,2,3};
    int arr2[] = {4,5,6};
    Array a1(arr,3);
    Array a2(arr2,3);
    Array a3;
    a3 = a1 + a2;
    ASSERT_EQ(5,a3[0]);
    ASSERT_EQ(7,a3[1]);
    ASSERT_EQ(9,a3[2]);
}

TEST(Array, Addition_B) {
    int arr[] = {1,2,3};
    int arr2[] = {4};
    Array a1(arr,3);
    Array a2(arr2,1);
    a1 += a2;
    ASSERT_EQ(5,a1[0]);
    ASSERT_EQ(2,a1[1]);
    ASSERT_EQ(3,a1[2]);
}

TEST(Array, Subtraction_A) {
    int arr[] = {1,2,3};
    int arr2[] = {4,5,6};
    Array a1(arr,3);
    Array a2(arr2,3);
    Array a3;
    a3 = a2 - a1;
    ASSERT_EQ(3,a3[0]);
    ASSERT_EQ(3,a3[1]);
    ASSERT_EQ(3,a3[2]);
}

TEST(Array, Subtraction_B) {
    int arr[] = {1,2,3};
    int arr2[] = {4};
    Array a1(arr,3);
    Array a2(arr2,1);
    a1 -= a2;
    ASSERT_EQ(-3,a1[0]);
    ASSERT_EQ(2,a1[1]);
    ASSERT_EQ(3,a1[2]);
}

TEST(Array, Increment) {
    int arr[] = {1,2,3};
    Array a1(arr,3);
    Array a2;
    a2 = a1++;
    ASSERT_EQ(2,a1[0]);
    ASSERT_EQ(3,a1[1]);
    ASSERT_EQ(4,a1[2]);
    ASSERT_EQ(1,a2[0]);
    ASSERT_EQ(2,a2[1]);
    ASSERT_EQ(3,a2[2]);
}

TEST(Array, Decrement) {
    int arr[] = {1,2,3};
    Array a1(arr,3);
    Array a2;
    a2 = a1--;
    ASSERT_EQ(0,a1[0]);
    ASSERT_EQ(1,a1[1]);
    ASSERT_EQ(2,a1[2]);
    ASSERT_EQ(1,a2[0]);
    ASSERT_EQ(2,a2[1]);
    ASSERT_EQ(3,a2[2]);
}

TEST(Array, DelAtIndex) {
    int arr[] = {1,2,3};
    Array a1(arr,3);
    int res[] ={1,3,0};
    Array a2(res,3);
    a1(1,2);
    ASSERT_EQ(true,a1==a2);
}



// Q2: BigInt  

TEST(BigInt, Constructors) { 
    string expected1="119622220865480194561963161495657715064383733760000000000";
    string expected2="99999";
    BigInt a(expected1);
    BigInt b(99999);
    BigInt c(a);
    string s1=(string)a;
    string s2=(string)b;
    string s3=(string)c;
    ASSERT_EQ(0, s1.compare(expected1));
    ASSERT_EQ(0, s2.compare(expected2));
    ASSERT_EQ(0, s3.compare(expected1));
    
}

TEST(BigInt, Addition) { 
        string str="9999999999999999999";
        string str2="-9999999999999999999";
	BigInt a(str);
	BigInt b=a+1000000;
	BigInt c;
	c=a+b;
    
        BigInt d(-2);
    BigInt e(str2);
        d+=e;
        
        string s1=(string)b; string expected1="10000000000000999999";
        string s2=(string)c; string expected2="20000000000000999998";
        string s3=(string)d; string expected3="-10000000000000000001";
        
        ASSERT_EQ(0, s1.compare(expected1));
        ASSERT_EQ(0, s2.compare(expected2));
        ASSERT_EQ(0, s3.compare(expected3));
       
        
}

TEST(BigInt, Subtraction) { 
        string str="10000000000000000000";
        string str2="-2389649237402842038420358230597297522834823748234";
    string str3="999999999999999";
	BigInt a(str);
	BigInt b=a-10000;
	BigInt c;
	c=a-b;
        BigInt d(str3);
        BigInt e(str2);
        d-=e;
        
        string s1=(string)b; string expected1="9999999999999990000";
        string s2=(string)c; string expected2="10000";
        string s3=(string)d; string expected3="2389649237402842038420358230597298522834823748233"; //2,389,649,237,402,842,038,420,358,230,597,298,522,834,823,748,233
        
        ASSERT_EQ(0, s1.compare(expected1));
        ASSERT_EQ(0, s2.compare(expected2));
        ASSERT_EQ(0, s3.compare(expected3));
    
}

TEST(BigInt, Mul) { 
        string str="-827364872364927409812348732487125212734582736498236498234";
	BigInt a(str);
	BigInt b;
	BigInt c=a*b;
    
    string str3="-12476423842223423234235";
    BigInt d(str3);
    a*=d;
        
        string s1=(string)c; string expected1="0";
        string s2=(string)a; string expected2="10322554819791919796058292527102125190455046402094774321142901271837361145840990";
                
        ASSERT_EQ(0, s1.compare(expected1));
        ASSERT_EQ(0, s2.compare(expected2));
        
    
}

TEST(BigInt, LogicalOperators) {
        string str1="119622220865480194561963161495657715064383733760000000000";
    string str2="5502622159812088949850305428800254892961651752960000000000";
    BigInt a(str1);
    BigInt c(str1);
    BigInt b(str2);
                    
        ASSERT_EQ(true, a==c);
        ASSERT_EQ(true, a== "119622220865480194561963161495657715064383733760000000000");
        ASSERT_EQ(false, a==b);
        ASSERT_EQ(false, a=="395740357023972035970293759348693475203957209357203752035");
        ASSERT_EQ(true, a!=b);
        ASSERT_EQ(true, a<=b);
        ASSERT_EQ(false, a>=b);
        ASSERT_EQ(false, a>b);
        ASSERT_EQ(true, a<b);
        
    
}

TEST(BigInt, UnaryOperators) { 
        string str1="9999999999999999999";
	string str2="10000000000000000000";
	BigInt a(str1);
	BigInt c(str1);
	BigInt b(str2);
    BigInt e;
    
	e = a++;
    
	string s1=(string)a; string expected1="10000000000000000000";
    string s5=(string)e; string expected5="9999999999999999999";
    ASSERT_EQ(0, s1.compare(expected1));
    ASSERT_EQ(0, s5.compare(expected5));
	
	--a;
	string s2=(string)a; string expected2="9999999999999999999";
        ASSERT_EQ(0, s2.compare(expected2));
	
	++b;
	string s3=(string)b; string expected3="10000000000000000001";
        ASSERT_EQ(0, s3.compare(expected3));
	
	b--;
	string s4=(string)b; string expected4="10000000000000000000";
        ASSERT_EQ(0, s4.compare(expected4));                
        
        
    
}

TEST(BigInt, CompundOperator ){
    
    BigInt a("123456789");
    BigInt b("-987654321");
    a *= b;
    EXPECT_EQ((string)a, "-121932631112635269");
    
    BigInt e("123456789");
    BigInt f("-987654321");
    e += f;
    EXPECT_EQ((string)e, "-864197532");
    
    BigInt c("987654321");
    BigInt d("-123456789");
    c -= d;
    EXPECT_EQ((string)c, "1111111110");

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




