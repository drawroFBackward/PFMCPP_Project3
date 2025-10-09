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
    int serialNumber = 1;
    std::string camera = "Canon";
    double smokeLevel = 0.0;
    bool detectFire();
    void soundAlarm(std::string announcement);
    void alertFireDepartment(int phoneLine);
};

bool FireAlarmSystem::detectFire()
{
    return smokeDetector == "Siemens" && smokeLevel > 50.0;
}

void FireAlarmSystem::soundAlarm(std::string announcement)
{
    if (detectFire())
    {
        std::cout << announcement << std::endl;
    }
}

void FireAlarmSystem::alertFireDepartment(int phoneLine)
{
    if (detectFire() && phoneLine > 0 && camera == "Canon")
    {
        std::cout << "Alerting fire department." << std::endl;
		// pretend to send camera footage and call fire department eg. callFireDept(phoneLine); sendFootage(camera, phoneLine);
    }
}

struct Keyboard
{
    int numberOfKeys = 88;
    int volume = 100;
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
        void playKey(int time);
        void stopKey();
        void tuneKey(float newTuning);
    };
    void playSound(Key key_1);
    void changeMode(std::string newMode);
    void displayMode();

    Key key_C;
};

void Keyboard::Key::playKey(int time)
{
    if (!isPressed)
    {
        isPressed = true;
        std::cout << "Playing key: " << name << " with frequency: " << frequency + tuning << " Hz for" << time << "seconds" << std::endl;
    }
}

void Keyboard::Key::stopKey()
{
    if (isPressed)
    {
        std::cout << "Stopping key: " << name << std::endl;
		isPressed = false;
    }
}

void Keyboard::Key::tuneKey(float newTuning)
{
	tuning += newTuning;
}

void Keyboard::playSound(Key key_1)
{
    if (mode == "Acoustic" && pedal)
    {
		key_1.playKey(5);
    }
	else if (mode == "Acoustic" && !pedal)
    {
		key_1.playKey(2);
		key_1.stopKey();
    }
}

void Keyboard::changeMode(std::string newMode)
{
	mode = newMode;
}

void Keyboard::displayMode()
{
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
    bool grabObject(bool objectPresent, float objectWeight);
    void moveObject(float position);
    void punch(float newPosition);
};

bool Arms::grabObject(bool objectPresent, float objectWeight)
{
    if (!objectPresent || objectWeight < strength)
    {
        return condition == "Good" && numberOfFingers == 5 && strength > 5.0f && reach > 5.0f;
	}
	return false;
}

void Arms::moveObject(float nextPosition)
{
    if (grabObject(true, 5.0))
    {
		position += nextPosition;
    }
}

void Arms::punch(float newPosition)
{
    if (condition == "Good" && strength > 5.0f)
    {
        position += newPosition;
    }
}

struct Legs
{
    int numberOfToes = 5;
    char side = 'l';
    float strength = 10;
    float kneeJointRange = 90.0f;
	int juggles = 0;
    std::string condition = "Injured";
    void kick(float newPosition);
    void juggleABall();
    float jump(float strengthUsed);
};

void Legs::kick(float newPosition)
{
    if (condition == "Good" && strength > 5.0f)
    {
        kneeJointRange += newPosition;
    }
}

void Legs::juggleABall()
{
    if (condition == "Good")
    {
        std::cout << "Juggling a ball with " << side << " leg." << std::endl;
		juggles += 1;
    }
}

float Legs::jump(float strengthUsed)
{
    if (condition == "Good" && strengthUsed > 5.0f && strengthUsed < strength)
    {
        return kneeJointRange * strengthUsed;
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
    void tear();
    void burn();
    float stretch(float amount);
};

void Skin::tear()
{
    if (condition == "Good" && thickness < 0.5f && age < 10)
    {
		condition = "Torn";
    }
}

void Skin::burn()
{
    if (condition == "Good" && thickness < 2.0f && age < 30)
    {
        condition = "Burnt";
    }
}

float Skin::stretch(float amount)
{
    if (condition == "Good" && thickness < 1.5f && age < 20)
    {
        return thickness * amount;
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
    void exercise(std::string intensity);
    int makeFriends(int attempts);
    void getAngry(int angerThreshhold);
};

void Human::exercise(std::string intensity)
{
	float position = (intensity == "High") ? 10.0f : 5.0f;
    leftArm.moveObject(position);
    leftLeg.kick(position);
}

int Human::makeFriends(int attempts)
{
	int numberOfFriends = 0;
	numberOfFriends += (personality_1.personalityType == "INFJ") ? 1 : 0;
	numberOfFriends += (health.condition == "Healthy") ? 1 : 0;
	numberOfFriends += (skin.condition == "Good") ? 1 : 0;
    return numberOfFriends * attempts;
}

void Human::getAngry(int angerThreshhold)
{
    if (personality_1.mood.happinessRating < angerThreshhold)
    {
        personality_1.mood.stressed = true;
    }
}


int main()
{
    std::cout << "good to go!" << std::endl;
}
