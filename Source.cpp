//Aashish Shenoy

// includes needed for various operators such as setprecision and setfill
#include <iostream>
#include <cstring>
#include <iomanip> 
#pragma warning(disable : 4996) //getting this warning trying to use localtime, still unsure how this works, but followed guides with given hyperlinks in error and was advised to add this to disable/suppress the warning

using namespace std;




// variables used globally
int hour; 
int minutes;
int seconds;
int menuSelect;
int hourAdd;
int minAdd;
int secondAdd;






// Menu function for display
void Menu() {
	int ss;
	for (ss = 0; ss < 27; ss++) putchar('*');
	cout << endl;
	cout << "* 1-Add One Hour          *" << endl;
	cout << "* 2-Add One Minute        *" << endl;
	cout << "* 3-Add Second            *" << endl;
	cout << "* 4-Exit Program          *" << endl;
	for (ss = 0; ss < 27; ss++) putchar('*');
	cout << endl;
}


// initially misread the directions, and created this section if inputs werent just 1 hour/minute, but rather multiple hours/minutes based on input

void AdditionalHours(int hoursAdded) { hourAdd += hoursAdded; };

void AdditionalMinutes(int minsAdded) {
	//local variables to handle excess mins
	int remainderMins = 0;
	int extraHours = 0;

	//handles excess mins if the amount added is more than 60 then calls to add to the additional hours function
	if (minsAdded >= 60) {
		extraHours = (minsAdded / 60);
		minsAdded = (minsAdded % 60);
		AdditionalHours(extraHours);
		minAdd += minsAdded;
	}
	else { minAdd += minsAdded; };

};

// adding seconds
void AdditionalSeconds(int secondsAdded) {
	int remainderSecs = 0;
	int extraMins = 0;

	if (secondsAdded >= 60) {
		extraMins = (secondsAdded / 60);
		secondsAdded = (secondsAdded % 60);
		AdditionalMinutes(extraMins);
		secondAdd += secondsAdded;
	}
	else { secondAdd += secondsAdded; };

};





// allocating initial time by using localtime, still unsure how this works.  
void GetTime() {
	time_t ttime = time(0);
	tm* local_time = localtime(&ttime);

	//variables used to store overflow time variables to in functions
	int tempHour = 0;
	int tempMins = 0;

	
	// takes into account the time added
	hour = local_time->tm_hour + hourAdd;
	
	minutes = local_time->tm_min + minAdd;
	if (minutes >= 60) {
		tempHour = (minutes / 60);
		hour = local_time->tm_hour + hourAdd + tempHour;
		minutes = (minutes % 60);

	};

	seconds = local_time->tm_sec + secondAdd;
	if (seconds >= 60) {
		tempMins = (minutes / 60);
		minutes = local_time->tm_min + minAdd + tempMins;
		seconds = (seconds % 60);

	};
}


//uses 24 hour function to calculate 12 hour time
void TwelveHrClock(int& hour, int& minutes, int& seconds) {

	
	bool isPM = false;
	string amOrPm = "A M";
	int hour12 = hour;  // had to use this variable to differentiate between 12 and 24 hour

	//determins AM / PM by using boolean
	if (hour >= 12) {
		isPM = true;
	}

	if (isPM == true) {
		amOrPm = "P M";
	}
	
		// time conversions for over 12, at noon, and under 12 respectively
	if (hour >= 24) {
		hour12 = hour12 % 24;
	}
	
	if (hour == 0) {
		hour12 = 12;
	}
	
	if (hour12 >= 13) {
		hour12 = hour12 % 12;
	}
	
	cout << "*" << "      " << "12-Hour Clock" << "      " << "*" << endl;
	cout << std::setfill('0') << "*" << "      " << std::setw(2) << hour12 << ":" << std::setw(2) << minutes << ":" << std::setw(2) << seconds << " " << amOrPm << "       " << "*" << endl;  // printing 12 hour time

}





void TwentyFourHrClock(int& hour, int& minutes, int& seconds) {   // 24 hr clock function
	int ss;
	for (ss = 0; ss < 27; ss++) putchar('*');  // adding '*'
	 
	cout << endl;
	cout << fixed << setprecision(2); 
	TwelveHrClock(hour, minutes, seconds);

	for (ss = 0; ss < 27; ss++) putchar('*');

	cout << endl<< endl;
	for (ss = 0; ss < 27; ss++) putchar('*');
	cout << endl;
	cout << "*" << "      " << "24-Hour Clock" << "      " << "*" << endl;
	cout << std::setfill('0') << "*" << "        " << std::setw(2) << hour << ":" << std::setw(2) << minutes << ":" << std::setw(2) << seconds << " " << "        " << "*" << endl;   // printing time with correct time formatting
	for (ss = 0; ss < 27; ss++) putchar('*');

	cout << endl<< endl;
}

void Menuselction(int menuSelect) {  //menu function
	
	int hourInput = 0;
	int minInput = 0;
	int secInput = 0;
	//defines variables for input
	
	if (menuSelect == 1) {  
		
		AdditionalHours(1);
		cout << endl;
		// adding 1 second, additionally has ability to add multiple hours
	}
	else if (menuSelect == 2) {
		
		AdditionalMinutes(1);
		cout << endl;
		// adding 1 second, additionally has ability to add multiple minutes
	}
	else if (menuSelect == 3) {
		
		AdditionalSeconds(1);
		cout << endl;
		// adding 1 second, additionally has ability to add multiple seconds
	}
	else if (menuSelect == 4) {
		cout << "Program Exit" << endl;
	}
	else {
		cout << "Choice unknown, try again" << endl << endl; // catches incorrect inputs
		cin.clear();
		cin.ignore(100, '\n');
	};


};



int main() {
	hourAdd = 0;
	minAdd = 0;
	secondAdd = 0;
	cout << fixed << setprecision(2);
	

	do {
		// calling 12 hour clock
		GetTime();
		// calling 24 hr clock
		TwentyFourHrClock(hour, minutes, seconds);
		// calling menu
		Menu();

		//getting user menu input
		cin >> menuSelect;

		Menuselction(menuSelect);

	} while (menuSelect != 4); // exit selection

}




