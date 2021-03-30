#include <string>
#include <vector>
#include <array>

using namespace std;

enum parts_indices
{
    HAT,
    NOSE,
    LEFT_EYE,
    RIGHT_EYE,
    LEFT_ARM,
    RIGHT_ARM,
    TORSO,
    BASE
};

// For use of whitespace
const string WS = " ";

// For upper and lower arms
const short UPPER = 0;
const short LOWER = 1;

// Different lengths 
const short INPUT_LENGTH = 8;
const short NUM_OF_OPTIONS = 4;
const int NUM_OF_PARTS = 8;

// Setting up possible hats
const string straw_hat = WS + "_===_";
const string mexican_hat = WS + " ___\n .....";
const string fez = WS + "  _\n  /_\\";
const string russian_hat = WS + " ___\n (_*_)";

// Setting up possible Torsos
const string buttons = " : ";
const string vest = "] [";
const string inward_arms = "> <";
const string none = "   ";

// Setting up possible Bases, some are already defined as torsos
const string feet = "\" \"";
const string flat = "___";

// Hat -> Left arm_1 -> Left eye -> Nose -> Right Eye -> Right_arm_1 -> Left arm 2 -> T1T2T3 -> Right arm 2 -> B1B2B3

// Setting up possible left arms
const string normal_left = " <";
const string up_left = "\\ ";
const string down_left = " /";
const string none_left = "  ";

// Setting up possible right arms
const string normal_right = " >";
const string up_right = "/ ";
const string down_right = " \\";
const string none_right = "  ";


string snowman(long int number);
int get_index(char digit);
array<string, NUM_OF_PARTS> fetch_parts(const long int input);

