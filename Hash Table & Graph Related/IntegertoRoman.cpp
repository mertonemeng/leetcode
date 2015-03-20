#include "stdafx.h"
#include <string>
#include <unordered_map>

using namespace std;

class IntegertoRoman {
public:
    static string intToRoman(int num) {
        unordered_map<int, string> hashTable;
		string result= "";

		generateHashTable(hashTable);

		int thousands = num/1000;
		num = num%1000;

		for(int i = 0; i < thousands; i++){
			result += hashTable[1000];
		}

		int key = (num/100) *100;

		if(hashTable.find(key) != hashTable.end()){
			result += hashTable[key];
			num = num%100;
		} else{
			if(num > 500){
				int hundreds = (num - 500)/100;

				result += hashTable[500];

				for(int i = 0; i < hundreds; i++){
					result += hashTable[100];
				}
				num = num%100;
			} else{
				int hundreds = (num)/100;

				for(int i = 0; i < hundreds; i++){
					result += hashTable[100];
				}
				num = num%100;
			}
		}

		key = (num/10) *10;

		if(hashTable.find(key) != hashTable.end()){
			result += hashTable[key];
			num = num%10;
		} else{
			if(num > 50){
				int tens = (num - 50)/10;

				result += hashTable[50];

				for(int i = 0; i < tens; i++){
					result += hashTable[10];
				}
				num = num%10;
			} else{
				int tens = (num)/10;

				for(int i = 0; i < tens; i++){
					result += hashTable[10];
				}
				num = num%10;
			}
		}

		key = num;

		if(hashTable.find(key) != hashTable.end()){
			result += hashTable[key];
		} else{
			if(num > 5){
				int ones = num - 5;

				result += hashTable[5];

				for(int i = 0; i < ones; i++){
					result += hashTable[1];
				}
			} else{
				int ones = num;

				for(int i = 0; i < ones; i++){
					result += hashTable[1];
				}
			}
		}

		return result;
    }

	static void generateHashTable(unordered_map<int, string> &hashTable){
		hashTable[1] = "I";
		hashTable[4] = "IV";
		hashTable[5] = "V";
		hashTable[9] = "IX";
		hashTable[10] = "X";
		hashTable[40] = "XL";
		hashTable[50] = "L";
		hashTable[90] = "XC";
		hashTable[100] = "C";
		hashTable[400] = "CD";
		hashTable[500] = "D";
		hashTable[900] = "CM";
		hashTable[1000] = "M";
	}
};