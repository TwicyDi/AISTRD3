#include "stdafx.h"
#include "CppUnitTest.h"
#include "..//main//main.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(encode_test_eng_string)
		{
			List <char> sort;
			string str = "hello world";
			string str2 = "10011100000010100001101011100101";
			string encode_str;
			encode_str = encode(str, sort);
			Assert::AreEqual(encode_str, str2);
		}

		TEST_METHOD(encode_test_number_string)
		{
			List <char> sort;
			string str = "123";
			string str2 = "00011";
			string encode_str;
			encode_str = encode(str, sort);
			Assert::AreEqual(encode_str, str2);
		}

		TEST_METHOD(decode_test_eng_string)
		{
			List <char> sort;
			string str = "hello world";
			
			string decode_str;
			string encode_str;
			encode_str = encode(str, sort);
			decode_str = decode(encode_str, sort);
			Assert::AreEqual(decode_str, str);
		}

		TEST_METHOD(decode_test_number_string)
		{
			List <char> sort;
			string str = "123";
			string decode_str;
			string encode_str;
			encode_str = encode(str, sort);
			decode_str = decode(encode_str, sort);
			Assert::AreEqual(decode_str, str);
		}

		TEST_METHOD(encode_test_empty_string)
		{
			List <char> sort;
			string str = "";
			string encode_str;
			encode_str = encode(str, sort);
			Assert::AreEqual(encode_str, str);
		}

		TEST_METHOD(decode_test_empty_string)
		{
			List <char> sort;
			string str = "";
			string encode_str;
			string decode_str;
			encode_str = encode(str, sort);
			decode_str = decode(encode_str, sort);
			Assert::AreEqual(decode_str, str);
		}
	};
}

