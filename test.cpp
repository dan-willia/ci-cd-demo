#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>

TEST_CASE ( "Factorials are computed", "[factorial]") // tag
{
  CHECK( Factorial(0) == 1 ); // assertion
  REQUIRE( Factorial(1) == 1 );
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
  REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE("incrementing values in integer vector", "[addN]")
{
	std::vector<int> v{1,2,3,5,6,7,8,10};

	SECTION("checking with +ve n")
  {
		int n=5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == 6 );
		REQUIRE( res[v.size()-1] == 15 );
		REQUIRE(res[random] == v[random]+n);
	}
	SECTION("checking with -ve n")
  {
		int n=-5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == -4 );
		REQUIRE( res[v.size()-1] == 5 );
		REQUIRE(res[random] == v[random]+n);
	}
}

TEST_CASE("splitting a string on a separator into a vector of strings", "[Split]") 
{
	SECTION("checking when separator is in string")
	{
		std::string s = "a space-separated string";
		std::string sep = " ";
		std::vector<std::string> res = Split(s, sep);
		REQUIRE(res.size() == 3);
		REQUIRE(res[0] == "a");
		REQUIRE(res[1] == "space-separated");
		REQUIRE(res[2] == "string");
	}
	
	SECTION("checking when separator is not in string")
	{
		std::string s = "a space-separated string";
		std::string sep = "/";
		std::vector<std::string> res = Split(s, sep);
		REQUIRE(res.size() == 1);
		REQUIRE(res[0] == s);
	}
}

TEST_CASE("removing all substrings", "[RemoveAllSubstrings]")
{
	SECTION("substring not in string")
	{
		std::string str = "hello world hello";
		std::string substr = "no";
		std::string res = RemoveAllSubstrings(str, substr);
		REQUIRE(res == str);
	}	

	SECTION("substring in string") 
	{
		std::string str = "hello world hello";
		std::string substr = "hello";
		std::string res = RemoveAllSubstrings(str, substr);
		REQUIRE(res == " world ");
	}

	SECTION("erase entire string")
	{
		std::string str = "aaaa";
		std::string substr = "aa";
		std::string res = RemoveAllSubstrings(str, substr);
		REQUIRE(res == "");
	}
}

TEST_CASE("remove first occurrence of substring in string (return new string)", "[RemoveFirstSubString]")
{
	SECTION("substring not in string")
	{
		std::string str = "hello world";
		std::string substr = "nope";
		std::string res = RemoveFirstSubstring(str, substr);
		REQUIRE(res == str);
	}

	SECTION("substring is at beginning of string")
	{
		std::string str = "hello world hello";
		std::string substr = "hello";
		std::string res = RemoveFirstSubstring(str, substr);
		REQUIRE(res == " world hello");
	}
	
	SECTION("substring is at end of string") 
	{
		std::string str = "hello world";
		std::string substr = "world";
		std::string res = RemoveFirstSubstring(str, substr);
		REQUIRE(res == "hello ");
	}
}

TEST_CASE("join all strings in a vector together with glue string", "[Join]")
{
	std::vector<std::string>v_str{"hello", "world"};
	std::string glue = " ";
	std::string res = Join(v_str, glue);
	REQUIRE(res == "hello world");
}

TEST_CASE("remove ints from a if in b where a and b are vectors of ints", "[MatchVectors]")
{
	SECTION("nothing in common")
	{
		std::vector<int>a{0,1};
		std::vector<int>b{2,3};
		std::vector<int>res = MatchVectors(a, b);
		REQUIRE(res == a);
	}

	SECTION("some (not all) in common")
	{
		std::vector<int>a{0,1,2};
		std::vector<int>b{2,3,4};
		std::vector<int>res = MatchVectors(a, b);
		std::vector<int>expected{0,1};
		REQUIRE(res == expected);
	}

	SECTION("all in common")
	{
		std::vector<int>a{0,1,2};
		std::vector<int>b{0,1,2};
		std::vector<int>res = MatchVectors(a, b);
		std::vector<int>expected{};
		REQUIRE(res == expected);
	}

	SECTION("multiple instances of an element removed from a")
	{
		std::vector<int>a{0,1,2,2};
		std::vector<int>b{2,3,4};
		std::vector<int>res = MatchVectors(a, b);
		std::vector<int>expected{0,1};
		REQUIRE(res == expected);
	}

	SECTION("multiple different elements removed from a")
	{
		std::vector<int>a{0,1,2};
		std::vector<int>b{1,2,4};
		std::vector<int>res = MatchVectors(a, b);
		std::vector<int>expected{0};
		REQUIRE(res == expected);
	}
}

TEST_CASE("factor out all twos, return remaining factor", "[RemoveTwos]")
{
	SECTION("odd numbers")
	{
		int x = 3;
		int y = 21;
		int z = 101;
		int ret1 = RemoveTwos(x);
		REQUIRE(ret1 == x);
		int ret2 = RemoveTwos(y);
		REQUIRE(ret2 == y);
		int ret3 = RemoveTwos(z);
		REQUIRE(ret3 == z);
	}

	SECTION("even numbers")
	{
		int x = 16;
		int y = 26;
		int z = 52;
		int ret1 = RemoveTwos(x);
		REQUIRE(ret1 == 1);
		int ret2 = RemoveTwos(y);
		REQUIRE(ret2 == 13);
		int ret3 = RemoveTwos(z);
		REQUIRE(ret3 == 13);
	}

	SECTION("negative even numbers") 
	{
		int x = -16;
		int y = -26;
		int z = -52;
		int ret1 = RemoveTwos(x);
		REQUIRE(ret1 == -1);
		int ret2 = RemoveTwos(y);
		REQUIRE(ret2 == -13);
		int ret3 = RemoveTwos(z);
		REQUIRE(ret3 == -13);
	}

	SECTION("negative odd numbers")
	{
		int x = -3;
		int y = -21;
		int z = -101;
		int ret1 = RemoveTwos(x);
		REQUIRE(ret1 == x);
		int ret2 = RemoveTwos(y);
		REQUIRE(ret2 == y);
		int ret3 = RemoveTwos(z);
		REQUIRE(ret3 == z);
	}

	SECTION("zero")
	{
		int x = 0;
		int ret1 = RemoveTwos(x);
		REQUIRE(ret1 == x);
	}

}