 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2
 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Foot
{
    float size;
    void stepForward();
    float stepSize(float size, int speed);//speed is int as howFast in Person is int
};

void Foot::stepForward()
{
    (void)this;
	// not quite sure what to put here
}

float Foot::stepSize(float size, int speed)//speed is int as howFast in Person is int
{
    return size * speed;
}

struct Person
{
    int age;
    int height;
	float hairLength;
    float GPA;
	unsigned int SATScore;
	int howFast;
	bool startWithLeftFoot;
	float dist = 0.0f;
    Foot leftFoot;
    Foot rightFoot;
	void run(int howFast, bool startWithLeftFoot);
};

void Person::run(int howFast, bool startWithLeftFoot)
{
    if(startWithLeftFoot)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
	}
	dist += leftFoot.stepSize(leftFoot.size, howFast) + rightFoot.stepSize(rightFoot.size, howFast);
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */


struct Camera
{
    std::string lens = "Canon";
    std::string film = "Polaroid";
    float zoom = 10.0f;
    float shutterSpeed = 100.0f;
    bool captureButton = false;
	bool flashEnabled = false;
    double takePicture(std::string lens, std::string film, float zoom, float shutterSpeed, bool captureButton);
    double takeVideo(std::string lens, std::string film, float zoom, float shutterSpeed, bool captureButton);
    void flash();
};

double Camera::takePicture(std::string lens, std::string film, float zoom, float shutterSpeed, bool captureButton)
{
    if (captureButton && film == "Polaroid" && lens == "Canon")
    {
        return zoom * shutterSpeed;
	}
    return 0.0;
}

double Camera::takeVideo(std::string lens, std::string film, float zoom, float shutterSpeed, bool captureButton)
{
	double video = 0.0;
    if (captureButton && film == "Polaroid" && lens == "Canon")
    {
		for (int i = 0; i < 10; ++i)
        {
			video += zoom * shutterSpeed;
        }
    }
    return video;
}

void Camera::flash()
{
	flashEnabled = true;
}

struct CoffeeMaker
{
    int amountOfWater = 100;
    int amountOfCoffeeBeanX = 10;
    int amountOfCoffeeBeanY = 10;
    std::string interface = "Touchscreen";
    int timer = 10;
    void makeCoffee(int amountOfWater, int amountOfCoffeeBeanX, int amountOfCoffeeBeanY, std::string interface, int timer);
    void receiveCoffeeRequest(int amountOfWater, int amountOfCoffeeBeanX, int amountOfCoffeeBeanY);
    std::string declineCoffeeRequest(int amountOfWater, int amountOfCoffeeBeanX, int amountOfCoffeeBeanY);
};

struct FireAlarmSystem
{
    std::string smokeDetector = "Siemens";
    std::string speaker = "Sony";
    int phoneLine = 1;
    std::string camera = "Canon";
    double memory = 100.0;
    bool detectFire(std::string smokeDetector, std::string camera, double memory);
    void soundAlarm(std::string speaker);
    void alertFireDepartment(int phoneLine, std::string camera, double memory);
};

struct Keyboard
{
    int numberOfKeys = 88;
    float volume = 10.0f;
    std::string mode = "Acoustic";
    double lcdScreen = 10.0;
    bool pedal = false;
    struct Key
    {
        char name;
        bool isPressed;
        float frequency;
        bool isBlackKey;
        float tuning;
        void playKey(char name, bool isPressed, float frequency, float tuning);
        void stopKey(char name, bool isPressed);
        void tuneKey(char name, float tuning);
    };
    void playSound(float volume, std::string mode, bool pedal);
    void changeMode(std::string mode);
    void displayMode(std::string mode, double lcdScreen);

    Key key_1;
};

struct Arms
{
    int numberOfFingers = 5;
    char side = 'l';
    float strength = 10.0f;
    float reach = 10.0f;
    std::string condition = "Good";
    bool grabObject(int numberOfFingers, char side, float strength, float reach, std::string condition);
    void moveObject(int numberOfFingers, char side, float strength, float reach, std::string condition);
    void punch(char side, float strength, std::string condition);
};

struct Legs
{
    int numberOfToes = 5;
    char side = 'l';
    int strength = 10;
    float kneeJointRange = 90.0f;
    std::string condition = "Injured";
    void kick(int numberOfToes, char side, int strength, float kneeJointRange, std::string condition);
    void juggleABall(char side, std::string condition);
    float jump(char side, int strength, float kneeJointRange, std::string condition);
};

struct Skin
{
    std::string color = "Brown";
    float thickness = 1.0f;
    double wrinkles = 10.0;
    int age = 30;
    std::string condition = "Burnt";
    void tear(float thickness, int age, std::string condition);
    void burn(float thickness, int age, std::string condition);
    float stretch(float thickness, int age, std::string condition);
};

struct Health
{
    char bloodType = 'A';
    float weight = 100.0f;
    float height = 180.0f;
    int sleepTimeInHours = 8;
    std::string condition = "Sick";
    std::string changeCondition(std::string condition, int sleepTimeInHours, float weight, float height);
    float gainWeight(float weight, int sleepTimeInHours, std::string condition);
    float increaseHeight(float height, int sleepTimeInHours, std::string condition);
};

struct Personality
{
    float iq = 200.0f;
    char gender = 'F';
    std::string personalityType = "INFJ";
    int interactionsPerDay = 10;
    bool isIntrovert = true;
    struct Mood
    {
        int happinessRating;
        bool stressed;
        int energyLevel;
        int age;
        std::string environment;
        float probabilityOfChangingMood(int happinessRating, bool stressed, int energyLevel, int age, std::string environment);
        int timeToChangeMood(int happinessRating, bool stressed, int energyLevel, int age, std::string environment);

    };
    bool goToWork(std::string personalityType, int interactionsPerDay);
    std::string learnSkill(float iq, std::string personalityType);
    Mood newMood(std::string personalityType, int interactionsPerDay, bool isIntrovert, Mood Mood);

    Mood Mood;
};

struct Human
{
    Arms leftArm;
    Legs leftLeg;
    Skin skin;
    Health health;
    Personality personality_1;
    void excercise(Arms leftArm, Legs leftLeg, Skin skin, Health health, Personality personality_1);
    int makeFriends(Personality personality_1, Health health, Skin skin);
    void getAngry(Personality personality_1);
};








int main()
{
    std::cout << "good to go!" << std::endl;
}
