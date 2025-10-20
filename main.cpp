/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.
    Show me that you understand how to use these language features.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable that IS NOT initialized in-class
    float b { 2.f }; //a member variable that IS initialized in-class
    UDT() : a(0) { } // 'constructor-initializer-list' initializing the member that wasn't initialized in-class.
    void printAandB()  //the member function
    {
        std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //2) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printAandB(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()


// first 5 structs will have member variables initialized in-class, next 5 structs will have member variables initialized in the constructor member initializer list.
// gonna ignore step 2 as some of my member functions already use initialized member variables (via std::cout statements, caluculation, return, etc).

struct Camera
{
	Camera();
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

Camera::Camera()
{
    std::cout << "Camera being constructed!" << std::endl;
}   

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
	CoffeeMaker();
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

CoffeeMaker::CoffeeMaker()
{
    std::cout << "CoffeeMaker being constructed!" << std::endl;
}

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
	FireAlarmSystem();
    std::string smokeDetector = "Siemens";
    std::string speaker = "There's a fire";
    int serialNumber = 1;
    std::string camera = "Canon";
    double smokeLevel = 0.0;
    bool detectFire();
    void soundAlarm(std::string announcement);
    void alertFireDepartment(int phoneLine);
};

FireAlarmSystem::FireAlarmSystem()
{
    std::cout << "FireAlarmSystem being constructed!" << std::endl;
}

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
	Keyboard();
    int numberOfKeys = 88;
    int volume = 100;
    std::string mode = "Acoustic";
    double lcdScreen = 10.0;
    bool pedal = false;
    struct Key
    {
		Key();
        char name;
        bool isPressed;
        float frequency;
        bool isBlackKey;
        float tuning;
        void playKey(int time);
        void stopKey();
        void tuneKey(float newTuning);
    };
    void playSound(Key key);
    void changeMode(std::string newMode);
    void displayMode();

    Key key_1;
};

Keyboard::Keyboard()
{
    std::cout << "Keyboard being constructed!" << std::endl;
}

Keyboard::Key::Key() : name('C'), isPressed(false), frequency(261.63f), isBlackKey(false), tuning(0.0f)
{
    std::cout << "Key being constructed!" << std::endl;
}

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

void Keyboard::playSound(Key key)
{
    if (mode == "Acoustic" && pedal)
    {
		key.playKey(5);
    }
	else if (mode == "Acoustic" && !pedal)
    {
		key.playKey(2);
		key.stopKey();
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
	Arms();
    int numberOfFingers;
    char side;
    float strength;
    float reach;
    std::string condition;
    float position;
    bool grabObject(bool objectPresent, float objectWeight);
    void moveObject(float position);
    void punch(float newPosition);
};

Arms::Arms() : numberOfFingers(5), side('l'), strength(10.0f), reach(10.0f), condition("Good"), position(0.0f)
{
    std::cout << "Arms being constructed!" << std::endl;
}

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
	Legs();
    int numberOfToes;
    char side;
    float strength;
    float kneeJointRange;
	int juggles;
    std::string condition = "Injured";
    void kick(float newPosition);
    void juggleABall();
    float jump(float strengthUsed);
};

Legs::Legs() : numberOfToes(5), side('l'), strength(10.0f), kneeJointRange(10.0f), juggles(0)
{
    std::cout << "Legs being constructed!" << std::endl;
}

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
	Skin();
    std::string color;
    float thickness;
    double wrinkles;
    int age;
    std::string condition;
    void tear();
    void burn();
    float stretch(float amount);
};

Skin::Skin() : color("Light"), thickness(1.0f), wrinkles(0.0), age(0), condition("Good")
{
    std::cout << "Skin being constructed!" << std::endl;
}

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
	Health();
    char bloodType;
    float weight;
    float height;
    int sleepTimeInHours;
    std::string condition;
    void changeCondition(std::string newCondition);
    float gainWeight(float weightMultiplier);
    float increaseHeight(float heightMultiplier);
};

Health::Health() : bloodType('O'), weight(140.0f), height(170.0f), sleepTimeInHours(7), condition("Unhealthy")
{
    std::cout << "Health being constructed!" << std::endl;
}

void Health::changeCondition(std::string newCondition)
{
    if (sleepTimeInHours >= 8 && weight < 150.0f && height > 150.0f)
    {
        condition = newCondition;
    }
}

float Health::gainWeight(float weightMultiplier)
{
    if (condition == "Healthy" && sleepTimeInHours < 6)
    {
        weight = weight * weightMultiplier;
    }
    return weight;
}

float Health::increaseHeight(float heightMultiplier)
{
    if (condition == "Healthy" && sleepTimeInHours >= 8)
    {
        height = height * heightMultiplier;
    }
    return height;
}

struct Personality
{
	Personality();
    float iq = 200.0f;
    char gender = 'F';
    std::string personalityType = "INFJ";
    int interactionsPerDay = 10;
    bool isIntrovert = true;
    struct Mood
    {
		Mood();
        int happinessRating;
        bool stressed;
        int energyLevel;
        int age;
        std::string environment;
        float probabilityOfChangingMood();
        int timeToChangeMood();
		void improveMood();
    };
    bool goToWork(std::string dayOfTheWeek);
    bool learnSkill();
    void resetMoodParams();

    Mood mood;
};

Personality::Personality()
{
    std::cout << "Personality being constructed!" << std::endl;
}

Personality::Mood::Mood() : happinessRating(50), stressed(false), energyLevel(50), age(25), environment("Calm")
{
    std::cout << "Mood being constructed!" << std::endl;
}

float Personality::Mood::probabilityOfChangingMood()
{
    float probability = 0.0f;
	probability += stressed ? 20.0f : 0.0f;
	probability += (happinessRating < 5) ? 30.0f : 0.0f;
	probability += (energyLevel < 5) ? 25.0f : 0.0f;
	probability += (age < 18) ? 15.0f : 0.0f;
	probability += (environment == "Noisy") ? 10.0f : 0.0f;
    return probability;
}

int Personality::Mood::timeToChangeMood()
{
    int time = 0;
    time += happinessRating * 2;
	time += stressed ? 0 : 10;
    time += (10 - energyLevel) * 2;
	time += (age < 18) ? 0 : 5;
    return time;
}

void Personality::Mood::improveMood()
{
    happinessRating += 10;
	stressed = false;
    energyLevel += 10;
    environment =  "Calm";
}

bool Personality::goToWork(std::string dayOfTheWeek)
{
    return !(dayOfTheWeek == "Saturday" || dayOfTheWeek == "Sunday");
}

bool Personality::learnSkill()
{
    return iq > 100.0f && personalityType == "INFJ";
}

void Personality::resetMoodParams()
{
    if (personalityType == "INFJ" && interactionsPerDay < 5 && isIntrovert)
    {
        mood.happinessRating = 10;
        mood.stressed = false;
        mood.energyLevel = 10;
        mood.environment = "Calm";
    }
}

struct Human
{
	Human();
    Arms leftArm, rightArm;
    Legs leftLeg, rightLeg;
    Skin skin;
    Health health;
    Personality personality_1;
    void exercise(std::string intensity);
    int makeFriends(int attempts);
    void getAngry(int angerThreshhold);
};

Human::Human() : leftArm(), rightArm(), leftLeg(), rightLeg(), skin(), health(), personality_1()
{
    std::cout << "Human being constructed!" << std::endl;
	rightArm.side = 'r';
	rightLeg.side = 'r';
}

void Human::exercise(std::string intensity)
{
	float position = (intensity == "High") ? 10.0f : 5.0f;
    leftArm.moveObject(position);
	rightArm.moveObject(position);
    leftLeg.kick(position);
	rightLeg.kick(position);
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
	Example::main();

	/*
		add your code between here
		*/
	Camera camera1;

	CoffeeMaker coffeeMaker1;

	FireAlarmSystem fireAlarmSystem1;

	Keyboard keyboard1;

	Keyboard::Key keyC;

	keyboard1.key_1 = keyC;

	Arms leftArm;

	Arms rightArm;

	Legs rightLeg;

	Legs leftLeg;

	Skin skin1;

	Health health1;

	Personality personality1;

	Personality::Mood mood1;

    Human human1;
    // Calling member functions for each instance
	std::cout << camera1.takePicture(5.0f, 0.5f) << std::endl;
    std::cout << camera1.takeVideo(5.0f, 0.5f, 10.0f) << std::endl;
    camera1.flash();
	coffeeMaker1.makeCoffee(50, 5, 5);
    coffeeMaker1.receiveCoffeeRequest(50, 5, 5);
	coffeeMaker1.requestForRefill();
	fireAlarmSystem1.smokeLevel = 60.0;
    //detectFire is called in following functions, so not calling it seperately
    fireAlarmSystem1.soundAlarm("Fire detected!");
    fireAlarmSystem1.alertFireDepartment(1234567890);
    keyboard1.key_1.tuneKey(5.0f);
    keyboard1.playSound(keyC); //calls other key functions
    keyboard1.changeMode("Electric");
    keyboard1.displayMode();
    leftArm.grabObject(true, 5.0f);
    leftArm.moveObject(10.0f);
    leftArm.punch(5.0f);
    std::cout << "Left arm position: " << leftArm.position << std::endl;
    rightLeg.juggleABall();
    rightLeg.kick(5.0f);
    std::cout << "Jump height: " << rightLeg.jump(8.0f) << std::endl;
    skin1.burn();
    skin1.tear();
    std::cout << "Skin stretched by: " << skin1.stretch(5.0f) << "mm" << std::endl;
    health1.changeCondition("Healthy");
    std::cout << "New weight: " << health1.gainWeight(1.1f) << std::endl;
	std::cout << "New height: " << health1.increaseHeight(1.05f) << std::endl;
    std::cout << "Mood change probability: " << personality1.mood.probabilityOfChangingMood() << "%" << std::endl;
	std::cout << "Time to change mood: " << personality1.mood.timeToChangeMood() << " minutes" << std::endl;
	personality1.mood.improveMood();
	personality1.resetMoodParams();
	personality1.goToWork("Monday");
	std::cout << (personality1.learnSkill() ? "Can learn new skill" : "Cannot learn new skill") << std::endl;
    human1.exercise("High");
	std::cout << "Friends made: " << human1.makeFriends(3) << std::endl;
	human1.getAngry(5);
	/*
		and here
		*/
    std::cout << "good to go!" << std::endl;
}
