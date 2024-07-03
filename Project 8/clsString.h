#pragma once
#include<iostream>
#include<vector>

using namespace std;

class clsString
{

private:

	string _Value;

protected:


	static	enum enWhatYouCount { SmallLetter = 0, CapitalLetter = 1, Punct = 2, Alpha = 3, Vowel = 4, All = 4 };
	static int CountLetter(string S, int Lingth, enWhatYouCount WhatYouCount = enWhatYouCount::All)
	{
		int Counter = 0;

		if (WhatYouCount == enWhatYouCount::All)
			return Lingth;


		for (int i = 0; i < Lingth; i++)
		{
			if (WhatYouCount == enWhatYouCount::CapitalLetter && isupper(S[i]))
				Counter++;
			else if (WhatYouCount == enWhatYouCount::SmallLetter && islower(S[i]))
				Counter++;
			else if (WhatYouCount == enWhatYouCount::Alpha && isalpha(S[i]))
				Counter++;
			else if (WhatYouCount == enWhatYouCount::Punct && ispunct(S[i]))
				Counter++;
			else if (WhatYouCount == enWhatYouCount::Vowel && IsVowel(S[i]))
				Counter++;
		}
		return Counter;
	}

	static short CountMatchCase(string S, short Lingth, char CheckChar, bool MatchCase = true)
	{
		short  counter = 0;
		for (int i = 0; i < Lingth; i++)
		{
			if (MatchCase)
			{
				if (S[i] == CheckChar)
					counter++;
			}
			else
			{
				if (tolower(S[i]) == tolower(CheckChar))
					counter++;
			}
		}
		return counter;
	}

	static enum enTrim { trimLeft = 1, trimRight = 2, trimAll = 3 };
	static string Trim(string S1, enTrim trim)
	{
		if (trim == enTrim::trimLeft)
		{

			for (short i = 0; S1.length(); i++)
			{
				if (S1[i] != ' ')
				{
					return   S1.substr(i, S1.length() - i);
				}
			}
			return "";
		}

		else if (trim == enTrim::trimRight)
		{
			for (short i = S1.length(); i >= 0; i--)
			{
				if (S1[i] != ' ')
					return S1.substr(0, i + 1);
			}
			return "";
		}

		else if (trim == enTrim::trimAll)
		{
			return Trim(Trim(S1, enTrim::trimLeft), enTrim::trimRight);
		}

	}

	static vector<string> insertWoredInVector(string S)
	{
		string dump = " ", Word;
		int pos;
		vector<string>vString;
		while ((pos = S.find(dump)) != std::string::npos)
		{
			Word = S.substr(0, pos);
			if (Word != "")
			{
				vString.push_back(Word);
			}
			S.erase(0, pos + dump.length());
		}
		if (S != "")
			vString.push_back(S);

		return vString;
	}
	static vector<string> ReversWordVector(vector<string> vString)
	{
		vector<string>vStringRev;
		for (int i = vString.size() - 1; i >= 0; i--)
		{
			vStringRev.push_back(vString[i]);
		}
		return vStringRev;
	}

	static enum enMatshing { Matsh = 1, NotMatsh = 2 };
	static vector<string> ReplaceInVectorWords(vector<string>vString, string Word, string WordRep, enMatshing Matshing = enMatshing::Matsh)
	{
		vector<string>vReblace;
		for (string& i : vString)
		{
			if (Matshing == enMatshing::Matsh)
			{
				if (i == Word)
				{
					i = WordRep;
				}
			}
			else if (Matshing == enMatshing::NotMatsh)
			{
				if (i == Word)
				{
					i = WordRep;
				}
				else
				{
					i[0] = InvertLetterCase(i[0]);
					if (i == Word)
					{
						i = WordRep;
					}
					else
					{
						i[0] = InvertLetterCase(i[0]);
					}
				}
			}

			vReblace.push_back(i);
		}
		return vReblace;
	}

	static string ReplaceWords(string S1, string Word, string WordRep, enMatshing Matshing = enMatshing::Matsh)
	{
		vector<string> VString = insertWoredInVector(S1);

		VString = ReplaceInVectorWords(VString, Word, WordRep, Matshing);

		S1 = JoinString(VString, " ");

		return S1;
	}


public:

	clsString()
	{
		_Value = "";
	}
	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}
	string GetValue()
	{
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue))string Value;

	static string UpperFirstLetterOfEachWord(string S, int Lingth = 1)
	{
		bool FirstWord = true;
		if (Lingth > S.length())
		{
			Lingth = S.length();
		}

		for (int i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ' && FirstWord)
				S[i] = toupper(S[i]);
			FirstWord = (S[i] == ' ' ? true : false);
		}
		return S;

	}
	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value, _Value.length());
	}

	static string LowerFirstLetterOfEachWord(string S, int Lingth = 1)
	{
		bool FirstWord = true;
		if (Lingth > S.length())
		{
			Lingth = S.length();
		}
		for (int i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ' && FirstWord)
				S[i] = tolower(S[i]);
			FirstWord = (S[i] == ' ' ? true : false);
		}
		return S;
	}
	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value, _Value.length());
	}

	static	string LowerAllLetterOfEachWord(string S, int Lingth = 1)
	{
		if (Lingth > S.length())
		{
			Lingth = S.length();
		}
		for (int i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ')
				S[i] = tolower(S[i]);
		}
		return S;
	}
	void LowerAllLetterOfEachWord()
	{
		_Value = LowerAllLetterOfEachWord(_Value, _Value.length());
	}

	static string UpperAllLetterOfEachWord(string S, int Lingth = 1)
	{
		if (Lingth > S.length())
		{
			Lingth = S.length();
		}
		for (int i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ')
				S[i] = toupper(S[i]);
		}
		return S;
	}
	void UpperAllLetterOfEachWord()
	{
		_Value = UpperAllLetterOfEachWord(_Value, _Value.length());
	}

	static char InvertLetterCase(char C)
	{
		return (isupper(C) ? tolower(C) : toupper(C));
	}
	static string InvertAllLetterCase(string S, int Lingth = 1)
	{
		if (Lingth > S.length())
		{
			Lingth = S.length();
		}
		for (int i = 0; i < S.length(); i++)
			S[i] = InvertLetterCase(S[i]);
		return S;
	}
	void InvertAllLetterCase()
	{
		_Value = InvertAllLetterCase(_Value, _Value.length());
	}

	static short CounterSmallLetter(string S1)
	{
		return CountLetter(S1, S1.length(), SmallLetter);
	}
	short CounterSmallLetter()
	{
		return CounterSmallLetter(_Value);
	}

	static short CounterCapitalLetter(string S1)
	{
		return CountLetter(S1, S1.length(), CapitalLetter);
	}
	short CounterCapitalLetter()
	{
		return CounterCapitalLetter(_Value);
	}

	static short CounterPunct(string S1)
	{
		return CountLetter(S1, S1.length(), Punct);
	}
	short CounterPunct()
	{
		return CounterPunct(_Value);
	}


	static short CounterAlpha(string S1)
	{
		return CountLetter(S1, S1.length(), Alpha);
	}
	short CounterAlpha()
	{
		return CounterPunct(_Value);
	}

	static bool IsVowel(char Char1)
	{
		Char1 = tolower(Char1);
		return Char1 == 'a' || Char1 == 'e' || Char1 == 'i' || Char1 == 'o' || Char1 == 'u';
	}

	static short CounterVowel(string S1)
	{
		return CountLetter(S1, S1.length(), Vowel);
	}
	short CounterVowel()
	{
		return CountLetter(_Value, _Value.length(), Vowel);
	}

	static short CounterAllLatter(string S1)
	{
		return S1.length();
	}
	short CounterAllLatter()
	{
		return CounterAllLatter(_Value);
	}

	static short CountMatchCase(string S1, char CheckChar)
	{
		return CountMatchCase(S1, S1.length(), CheckChar, false);
	}
	short CountMatchCase(char CheckChar)
	{
		return CountMatchCase(_Value, CheckChar);
	}

	static void PrintVowelsInTheString(string S, short Lingth = 1)
	{
		if (Lingth > S.length())
		{
			Lingth = S.length();
		}
		for (int i = 0; i < Lingth; i++)
		{
			if (IsVowel(S[i]))
				cout << S[i] << "    ";
		}
		cout << endl;
	}
	void PrintVowelsInTheString()
	{
		return PrintVowelsInTheString(_Value, _Value.length());
	}

	static	void PrintEachWordInString(string S)
	{
		string delm = " ";

		short pos;

		while ((pos = S.find(delm)) != std::string::npos)
		{
			string Word = S.substr(0, pos);
			if (Word != "")
			{
				cout << Word << endl;
			}

			S.erase(0, pos + delm.length());
		}
		if (S != "")
			cout << S << endl;
	}
	void PrintEachWordInString()
	{
		return  PrintEachWordInString(_Value);
	}

	static short  NumberEachWordInString(string S)
	{
		string delm = " ";

		short pos, CounterWord = 0;

		while ((pos = S.find(delm)) != std::string::npos)
		{
			string Word = S.substr(0, pos);
			if (Word != "")
			{
				CounterWord++;
			}

			S.erase(0, pos + delm.length());
		}
		if (S != "")
			CounterWord++;
		return CounterWord;
	}
	short  NumberEachWordInString()
	{
		return NumberEachWordInString(_Value);
	}

	static vector<string>Split(string S, string delm)
	{
		vector<string>vWord;
		string Word;
		short pos = 0;
		while ((pos = S.find(delm)) != std::string::npos)
		{
			Word = S.substr(0, pos);
			//if (Word != "")
			//{
			vWord.push_back(Word);
			//}
			S.erase(0, pos + delm.length());
		}
		if (S != "")
			vWord.push_back(S);

		return vWord;
	}
	vector<string>Split(string delm)
	{
		return Split(_Value, delm);
	}

	static string TrimLeft(string S1)
	{
		return Trim(S1, trimLeft);
	}
	string TrimLeft()
	{
		return TrimLeft(_Value);
	}

	static string TrimRight(string S1)
	{
		return Trim(S1, trimRight);
	}
	string TrimRight()
	{
		return TrimRight(_Value);
	}

	static string TrimAll(string S1)
	{
		return Trim(S1, trimAll);
	}
	string TrimAll()
	{
		return TrimAll(_Value);
	}


	static string JoinString(vector<string> vString, string Delm)
	{
		string S1 = vString[0];

		for (short i = 1; i < vString.size(); i++)
		{
			S1 += Delm + vString[i];
		}
		return S1;
	}
	static string JoinString(string S[], short Lingth, string Delm)
	{
		string S1 = S[0];

		for (short i = 1; i < Lingth; i++)
		{
			S1 += Delm + S[i];
		}
		return S1;
	}

	static string ReverseWordsInString(string S1)
	{
		vector<string>vString = insertWoredInVector(S1);

		vString = ReversWordVector(vString);

		S1 = JoinString(vString, " ");

		return S1;
	}
	string ReverseWordsInString()
	{
		return ReverseWordsInString(_Value);
	}



	static string ReplaceWordsMatsh(string S1, string Word, string WordReplase)
	{
		return ReplaceWords(S1, Word, WordReplase);
	}
	string ReplaceWordsMatsh(string Word, string WordReplase)
	{
		return ReplaceWordsMatsh(_Value, Word, WordReplase);
	}


	static string ReplaceWordsNotMatsh(string S1, string Word, string WordReplase)
	{
		return ReplaceWords(S1, Word, WordReplase, NotMatsh);
	}
	string ReplaceWordsNotMatsh(string Word, string WordReplase)
	{
		return ReplaceWordsNotMatsh(_Value, Word, WordReplase);
	}

	static string RemoveAllPunctuations(string S1)
	{
		string S2 = "";
		for (char& i : S1)
		{
			if (!ispunct(i))
			{
				S2 += i;
			}
		}
		return S2;
	}
	string RemoveAllPunctuations()
	{
		return RemoveAllPunctuations(_Value);
	}


	static string NumberToText(int Number)
	{
		if (Number == 0)
		{
			return "";
		}
		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "","one","two","three","four","five","six","seven","eight","nine","ten",
			"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };

			return arr[Number] + " ";
		}
		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };

			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}
		if (Number >= 100 && Number <= 199)
		{
			return "One hundred " + NumberToText(Number % 100);
		}
		if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + "hundred " + NumberToText(Number % 100);
		}
		if (Number >= 1000 && Number <= 1999)
		{
			return "One thousand " + NumberToText(Number % 1000);
		}
		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + "thousand " + NumberToText(Number % 1000);
		}
		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One million " + NumberToText(Number % 1000000);
		}
		if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToText(Number / 1000000) + "million " + NumberToText(Number % 1000000);
		}
		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One billion " + NumberToText(Number % 1000000000);
		}
		if (Number >= 2000000000 && Number <= 999999999999)
		{
			return NumberToText(Number / 1000000000) + "billion " + NumberToText(Number % 1000000000);
		}
	}


};

