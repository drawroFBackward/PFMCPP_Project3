/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            ++bar.num;                    //2a), 5)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()


struct Camera
{
	Camera();
    std::string lens = "Canon";
    std::string film = "Polaroid";
    float zoomCapacity = 10.0f;
	float zoomLevel = 0.0f;
    float cameraSize = 100.0f;
    bool captureButton = false;
	bool flashEnabled = false;
    float takePicture(float zoom, float shutterSpeed);
	float takeVideo(float zoom, float shutterSpeed, int videoLength);// gonna modify this one to have the for loop
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

float Camera::takeVideo(float zoom, float shutterSpeed, int videoLength)
{
	float video = 0.0f;
	for (int i = 0; i < videoLength; i++) //gonna start at 0 so that I get (videoLength) number of frames
    {
		video += takePicture(zoom, shutterSpeed);
        std::cout << "frame " << i << std::endl;
        if (video >= 100.0f) 
        {
            std::cout << "out of memory at frame" << i << std::endl;
            return video;
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
    void makeDefaultCoffee();
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

void CoffeeMaker::makeDefaultCoffee()
{
    for (int i = 0; i < timer; i++)
    {
        std::cout << "Making coffee" << std::endl;
        std::cout << "time left till coffee is ready = " << timer - i << std::endl;//this is why i'm using post increment here
        coffeeAmount += 3;
        --water;
        --coffeeBeanY;
        --coffeeBeanX;
        std::cout << "current coffee amount = " << coffeeAmount << std::endl;

        if (water == 0 || coffeeBeanX == 0 || coffeeBeanY == 0)
        {
            if (i == timer)
            {
                std::cout << "finished making coffee" << std::endl;
			}
            std::cout << "out of ingredients" << std::endl;
            return;
        }
		std::cout << "finished making coffee" << std::endl;
    }
}

struct FireAlarmSystem
{
	FireAlarmSystem();
    std::string smokeDetector = "Siemens";
    std::string speaker = "There's a fire";
    int serialNumber = 1;
    std::string camera = "Canon";
    double smokeLevel;
    bool detectFire();
    void soundAlarm(std::string announcement);
    void alertFireDepartment(int phoneLine);
	void putOutFire();
};

FireAlarmSystem::FireAlarmSystem() : smokeLevel(20.0)
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

void FireAlarmSystem::putOutFire()
{
    while (detectFire())
    {
        smokeLevel -= 10.0;
        std::cout << "Putting out fire, current smoke level: " << smokeLevel << std::endl;
        if (smokeLevel <= 0.0)
        {
            std::cout << "Fire put out!" << std::endl;
            smokeLevel = 0.0;
            return;
        }
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
		void playTremolo();
    };
    void playSound(Key key);
    void changeMode(std::string newMode);
    void displayMode();
	void playMelody();

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

void Keyboard::Key::playTremolo()
{
    for (int i = 0; i < 5; i++)
    {
        playKey(1);
        stopKey();
    }
}//had no clue this was what it was called XD

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

void Keyboard::playMelody()
{
    std::string melody = "CDEFGABC";
    for (std::string::size_type i = 0; i < melody.size(); ++i)
    {
        std::cout << "Playing note: " << melody[i] << std::endl;
    }
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
	float moveObjectByPunch(int numberOfPunches);
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

float Arms::moveObjectByPunch(int numberOfPunches)
{
    float totalMovement = 0.0f;
    for (int i = 0; i < numberOfPunches; ++i)
    {
		float oldPosition = position;
        punch(2.0f);
        totalMovement += (position - oldPosition);
	    std::cout << "Punch " << i << " moved the object by " << (position - oldPosition) << std::endl;
    }
	std::cout << "Total movement after " << numberOfPunches << " punches: " << totalMovement << std::endl;
    return totalMovement;
}

struct Legs
{
	Legs();
    int numberOfToes;
    char side;
    float strength;
    float kneeJointRange;
	int juggles;
    std::string condition = "Good";
    void kick(float newPosition);
    void juggleABall();
    float jump(float strengthUsed);
	float run(int time);
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

float Legs::run(int time)
{
    float distance = 0.0f;
    for (int i = 0; i < time; ++i)
    {
        if (condition == "Good" && strength > 5.0f)
        {
            distance += strength * 0.5f;
            std::cout << "Running... distance covered: " << distance << " after " << i << " seconds." << std::endl;
			strength -= 0.5f; // fatigue
        }
        else
        {
			(strength < 5.0f) ? std::cout << "Cannot run due to fatigue" << std::endl : std::cout << "Cannot run due to bad condition" << std::endl;
            break;
        }
    }
    return distance;
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

	camera1.takeVideo(5.0f, 0.5f, 15);

	coffeeMaker1.makeDefaultCoffee();

	fireAlarmSystem1.putOutFire();

	keyboard1.playMelody();

	keyC.playTremolo();

	leftArm.moveObjectByPunch(5);

	rightLeg.run(10);


	/*
		and here
		*/
    std::cout << "good to go!" << std::endl;
}
