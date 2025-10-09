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

#include <iostream>

struct Foot
{
    int footSize;
    void stepForward();
    int stepSize(int size, int speed);//speed is int as howFast in Person is int
};

void Foot::stepForward()
{
    
}

int Foot::stepSize(int size, int speed)//speed is int as howFast in Person is int
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
	int dist = 0;
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
	dist += leftFoot.stepSize(leftFoot.footSize, howFast) + rightFoot.stepSize(rightFoot.footSize, howFast);
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
    float zoomCapacity = 10.0f;
    float cameraSize = 100.0f;
    bool captureButton = false;
	bool flashEnabled = false;
    float takePicture(float zoom, float shutterSpeed);
    float takeVideo(float zoom, float shutterSpeed, float videoLength);
    void flash();
};

float Camera::takePicture(float zoom, float shutterSpeed)
{
    if (captureButton && film == "Polaroid" && lens == "Canon")
    {
        return zoom * shutterSpeed;
	}
    return 0.0;
}

float Camera::takeVideo(float zoom, float shutterSpeed, float videoLength)
{
    if (captureButton && film == "Polaroid" && lens == "Canon")
    {
		return videoLength * zoom * shutterSpeed;
    }
	return 0.0;
}

void Camera::flash()
{
	flashEnabled = true;
}

struct CoffeeMaker
{
    int water = 100;
    int coffeeBeanX = 10;
    int coffeeBeanY = 10;
	int coffeeAmount = 0;
    std::string interface = "Touchscreen";
    int timer = 10;
    void makeCoffee(int amountOfWater, int amountOfCoffeeBeanX, int amountOfCoffeeBeanY);
    void receiveCoffeeRequest(int amountOfWater, int amountOfCoffeeBeanX, int amountOfCoffeeBeanY);
    void requestForRefill();
};

void CoffeeMaker::makeCoffee(int amountOfWater, int amountOfCoffeeBeanX, int amountOfCoffeeBeanY)
{
    coffeeAmount += ((amountOfWater / 10) + (amountOfCoffeeBeanX + amountOfCoffeeBeanY) / 20) * timer;   
}

void CoffeeMaker::receiveCoffeeRequest(int amountOfWater, int amountOfCoffeeBeanX, int amountOfCoffeeBeanY)
{
    if (amountOfWater > 0 && amountOfCoffeeBeanX > 0 && amountOfCoffeeBeanY > 0)
    {
        std::cout << "Coffee request received." << std::endl;
		makeCoffee(amountOfWater, amountOfCoffeeBeanX, amountOfCoffeeBeanY);
    }
    else
    {
		requestForRefill();
    }
}

void CoffeeMaker::requestForRefill()
{
	std::cout << "Refill ingredients." << std::endl;
}

struct FireAlarmSystem
{
    std::string smokeDetector = "Siemens";
    std::string speaker = "There's a fire";
    int phoneLine = 1;
    std::string camera = "Canon";
    double smokeLevel = 0.0;
    bool detectFire(std::string smokeDetector, double memory);
    void soundAlarm(std::string speaker);
    void alertFireDepartment(int phoneLine, std::string camera);
};

bool FireAlarmSystem::detectFire(std::string smokeDetector, double smokeLevel)
{
    return smokeDetector == "Siemens" && smokeLevel > 50.0;
}

void FireAlarmSystem::soundAlarm(std::string speaker)
{
    if (detectFire(smokeDetector, smokeLevel))
    {
        std::cout << speaker << std::endl;
    }
}

void FireAlarmSystem::alertFireDepartment(int phoneLine, std::string camera)
{
    if (detectFire(smokeDetector, smokeLevel) && phoneLine > 0 && camera == "Canon")
    {
        std::cout << "Alerting fire department." << std::endl;
		// pretend to send camera footage and call fire department eg. callFireDept(phoneLine); sendFootage(camera, phoneLine);
    }
}

struct Keyboard
{
    int numberOfKeys = 88;
    int volume = 10;
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
        void tuneKey(float tuning);
    };
    void playSound(Key key_1, int volume, std::string mode, bool pedal);
    void changeMode(std::string mode);
    void displayMode(std::string mode, double lcdScreen);

    Key key_1;
};

void Keyboard::Key::playKey(char name, bool isPressed, float frequency, float tuning)
{
    if (!isPressed)
    {
        isPressed = true;
        std::cout << "Playing key: " << name << " with frequency: " << frequency + tuning << " Hz" << std::endl;
    }
}

void Keyboard::Key::stopKey(char name, bool isPressed)
{
    if (isPressed)
    {
        std::cout << "Stopping key: " << name << std::endl;
		isPressed = false;
    }
}

void Keyboard::Key::tuneKey(float tuning)
{
	tuning += tuning;
}

void Keyboard::playSound(Key key_1, int volume, std::string mode, bool pedal)
{
    if (mode == "Acoustic" && pedal)
    {
		key_1.playKey(key_1.name, key_1.isPressed, key_1.frequency, key_1.tuning);
    }
	else if (mode == "Acoustic" && !pedal)
    {
		key_1.playKey(key_1.name, key_1.isPressed, key_1.frequency, key_1.tuning);
		key_1.stopKey(key_1.name, key_1.isPressed);
    }
}

void Keyboard::changeMode(std::string mode)
{
	mode = mode;
}

void Keyboard::displayMode(std::string mode, double lcdScreen)
{
	//sending to console as no implementation for lcd screen
    std::cout << "Current mode: " << mode << " displayed on LCD screen size: " << lcdScreen << " inches" << std::endl;
}

struct Arms
{
    int numberOfFingers = 5;
    char side = 'l';
    float strength = 10.0f;
    float reach = 10.0f;
    std::string condition = "Good";
    float position;
    bool grabObject(int numberOfFingers, char side, float strength, float reach, std::string condition);
    void moveObject(int numberOfFingers, char side, float strength, float reach, std::string condition, float position);
    void punch(float position, float strength, std::string condition);
};

bool Arms::grabObject(int numberOfFingers, char side, float strength, float reach, std::string condition)
{
    return condition == "Good" && numberOfFingers == 5 && strength > 5.0f && reach > 5.0f;
}

void Arms::moveObject(int numberOfFingers, char side, float strength, float reach, std::string condition, float position)
{
    if (grabObject(numberOfFingers, side, strength, reach, condition))
    {
		position += position;
    }
}

void Arms::punch(float position, float strength, std::string condition)
{
    if (condition == "Good" && strength > 5.0f)
    {
        position += position;
    }
}

struct Legs
{
    int numberOfToes = 5;
    char side = 'l';
    int strength = 10;
    float kneeJointRange = 90.0f;
    std::string condition = "Injured";
    void kick(int strength, float kneeJointRange, std::string condition);
    void juggleABall(char side, std::string condition);
    float jump(int strength, float kneeJointRange, std::string condition);
};

void Legs::kick(int strength, float kneeJointRange, std::string condition)
{
    if (condition == "Good" && strength > 5)
    {
        kneeJointRange += kneeJointRange;
    }
}

void Legs::juggleABall(char side, std::string condition)
{
    if (condition == "Good")
    {
        std::cout << "Juggling a ball with " << side << " leg." << std::endl;
    }
}

float Legs::jump(int strength, float kneeJointRange, std::string condition)
{
    if (condition == "Good" && strength > 5)
    {
        return kneeJointRange;
    }
    return 0.0f;
}

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

void Skin::tear(float thickness, int age, std::string condition)
{
    if (condition == "Good" && thickness < 0.5f && age < 10)
    {
		condition = "Torn";
    }
}

void Skin::burn(float thickness, int age, std::string condition)
{
    if (condition == "Good" && thickness < 2.0f && age < 30)
    {
        condition = "Burnt";
    }
}

float Skin::stretch(float thickness, int age, std::string condition)
{
    if (condition == "Good" && thickness < 1.5f && age < 20)
    {
        return thickness * 1.1f;
    }
    return thickness;
}

struct Health
{
    char bloodType = 'A';
    float weight = 100.0f;
    float height = 180.0f;
    int sleepTimeInHours = 8;
    std::string condition = "Sick";
    std::string changeCondition(int sleepTimeInHours, float weight, float height);
    float gainWeight(float weight, int sleepTimeInHours, std::string condition);
    float increaseHeight(float height, int sleepTimeInHours, std::string condition);
};

std::string Health::changeCondition(int sleepTimeInHours, float weight, float height)
{
    if (sleepTimeInHours >= 8 && weight < 150.0f && height > 150.0f)
    {
        condition = "Healthy";
    }
    return condition;
}

float Health::gainWeight(float weight, int sleepTimeInHours, std::string condition)
{
    if (condition == "Healthy" && sleepTimeInHours < 6)
    {
        weight = weight * 1.1f;
    }
    return weight;
}

float Health::increaseHeight(float height, int sleepTimeInHours, std::string condition)
{
    if (condition == "Healthy" && sleepTimeInHours >= 8)
    {
        height = height * 1.1f;
    }
    return height;
}

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
		void improveMood();
    };
    bool goToWork(std::string personalityType, int interactionsPerDay);
    bool learnSkill(float iq, std::string personalityType);
    Personality::Mood newMood(std::string personalityType, int interactionsPerDay, bool isIntrovert, Mood Mood);

    Mood mood;
};

float Personality::Mood::probabilityOfChangingMood(int happinessRating, bool stressed, int energyLevel, int age, std::string environment)
{
    float probability = 0.0f;
	probability += stressed ? 20.0f : 0.0f;
	probability += (happinessRating < 5) ? 30.0f : 0.0f;
	probability += (energyLevel < 5) ? 25.0f : 0.0f;
	probability += (age < 18) ? 15.0f : 0.0f;
	probability += (environment == "Noisy") ? 10.0f : 0.0f;
    return probability;
}

int Personality::Mood::timeToChangeMood(int happinessRating, bool stressed, int energyLevel, int age, std::string environment)
{
    int time = 0;
    time += happinessRating * 2;
    if (!stressed)
    {
        time += 10;
    }
    time += (10 - energyLevel) * 2;
    if (age < 18)
    {
        time += 5;
    }
    if (environment == "Noisy")
    {
        time += 5;
    }
    return time;
}

void Personality::Mood::improveMood()
{
    happinessRating += 10;
	stressed = false;
    energyLevel += 10;
    environment =  "Calm";
}

bool Personality::goToWork(std::string personalityType, int interactionsPerDay)
{
    return personalityType == "INFJ" && interactionsPerDay < 5;
}

bool Personality::learnSkill(float iq, std::string personalityType)
{
    return iq > 100.0f && personalityType == "INFJ";
}

Personality::Mood Personality::newMood(std::string personalityType, int interactionsPerDay, bool isIntrovert, Personality::Mood mood)
{
    if (personalityType == "INFJ" && interactionsPerDay < 5 && isIntrovert)
    {
        mood.happinessRating = 10;
        mood.stressed = false;
        mood.energyLevel = 10;
        mood.environment = "Calm";
    }
    return mood;
}

struct Human
{
    Arms leftArm;
    Legs leftLeg;
    Skin skin;
    Health health;
    Personality personality_1;
    void exercise(Arms leftArm, Legs leftLeg);
    int makeFriends(Personality personality_1, Health health, Skin skin);
    void getAngry(Personality personality_1);
};

void Human::exercise(Arms leftArm, Legs leftLeg)
{
    leftArm.moveObject(5, 'l', 20.0f, 5.0f, "Good", 0.0f);
    leftLeg.kick(20.0f, 90.0f, "Good");
}

int Human::makeFriends(Personality personality_1, Health health, Skin skin)
{
	int numberOfFriends = 0;
    if (personality_1.personalityType == "INFJ")
    {
		numberOfFriends += 1;
    }
    if (health.condition == "Healthy")
    {
		numberOfFriends += 1;
    }
    if (skin.condition == "Good")
    {
		numberOfFriends += 1;
    }
    return numberOfFriends;
}

void Human::getAngry(Personality personality_1)
{
    if (personality_1.mood.happinessRating < 5)
    {
        personality_1.mood.stressed = true;
    }
}


int main()
{
    std::cout << "good to go!" << std::endl;
}
