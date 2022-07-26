/*
Ivanov 10-3-IIT 
Realization of the Facade pattern on the example of the lateote of the musicians
https://ru.wikipedia.org/wiki/%D0%A4%D0%B0%D1%81%D0%B0%D0%B4_(%D1%88%D0%B0%D0%B1%D0%BB%D0%BE%D0%BD_%D0%BF%D1%80%D0%BE%D0%B5%D0%BA%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F)
*/
#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

/** Abstract musician - not a mandatory part of the pattern, introduced to simplify the code */
class Musician {

	const char* name;

public:
	Musician(const char* name) {
		this->name = name;
	}

	virtual ~Musician() {}

protected:
	void output(const char* text) {
		std::cout << this->name << " " << text << "." << std::endl;
	}
};

/** Specific musicians */
class Vocalist : public Musician {

public:
	Vocalist(const char* name) : Musician(name) {}

	void singCouplet(const int coupletNumber) {
		char* text = strdup("sang verse number");
		strncat(text, std::to_string(coupletNumber).c_str(), 15);
		output(text);
	}

	void singChorus() {
		output("sang the chorus");
	}
};

class Guitarist : public Musician {

public:
	Guitarist(const char* name) : Musician(name) {}

	void playCoolOpening() {
		output("starts with a cool entry");
	}

	void playCoolRiffs() {
		output("plays cool riffs");
	}

	void playAnotherCoolRiffs() {
		output("playing other cool riffs");
	}

	void playIncrediblyCoolSolo() {
		output("gives an incredibly cool solo");
	}

	void playFinalAccord() {
		output("ends the song with a powerful chord");
	}
};

class Bassist : public Musician {

public:
	Bassist(const char* name) : Musician(name) {}

	void followTheDrums() {
		output("follows the reels");
	}

	void changeRhythm(const char* type) {
		char* text = strdup("moved to the rhythm");
		strncat(text, type, 15);
		strncat(text, "a", 15);
		output(text);
	}

	void stopPlaying() {
		output("finishes playing");
	}
};

class Drummer : public Musician {

public:
	Drummer(const char* name) : Musician(name) {}

	void startPlaying() {
		output("starts playing");
	}

	void stopPlaying() {
		output("finishes playing");
	}
};

/** The facade, in this case - the famous rock band */
class BlackSabbath {

	Vocalist* vocalist;
	Guitarist* guitarist;
	Bassist* bassist;
	Drummer* drummer;

public:

	BlackSabbath() {
		vocalist = new Vocalist("Ozzie Osbourne");
		guitarist = new Guitarist("Tony Iommi");
		bassist = new Bassist("Geezer Butler");
		drummer = new Drummer("Bill Ward");
	}

	~BlackSabbath() {
		delete vocalist;
		delete guitarist;
		delete bassist;
		delete drummer;
	}

	void playCoolSong() {
		guitarist->playCoolOpening();
		drummer->startPlaying();
		bassist->followTheDrums();
		guitarist->playCoolRiffs();
		vocalist->singCouplet(1);
		bassist->changeRhythm("chorus");
		guitarist->playAnotherCoolRiffs();
		vocalist->singChorus();
		bassist->changeRhythm("couplet");
		guitarist->playCoolRiffs();
		vocalist->singCouplet(2);
		bassist->changeRhythm("chorus");
		guitarist->playAnotherCoolRiffs();
		vocalist->singChorus();
		bassist->changeRhythm("couplet");
		guitarist->playIncrediblyCoolSolo();
		guitarist->playCoolRiffs();
		vocalist->singCouplet(3);
		bassist->changeRhythm("chorus");
		guitarist->playAnotherCoolRiffs();
		vocalist->singChorus();
		bassist->changeRhythm("couplet");
		guitarist->playCoolRiffs();
		bassist->stopPlaying();
		drummer->stopPlaying();
		guitarist->playFinalAccord();
	}
};

int main() {
	std::cout << "OUTPUT:" << std::endl;
	BlackSabbath* band = new BlackSabbath();
	band->playCoolSong();
	return 0;
}

/**
* Tony Iommi begins with a cool intro.
* Bill Ward starts to play.
* Guizer Butler follows the reels.
* Tony Iommi plays cool riffs.
* Ozzy Osbourne sang verse number 1.
* Guizer Butler switched to chorus rhythm.
* Tony Iommi plays other cool riffs.
* Ozzy Osbourne sang the chorus.
* Guizer Butler moved to the rhythm of the couplet.
* Tony Iommi plays cool riffs.
* Ozzy Osbourne sang verse 2.
* Guizer Butler switched to chorus rhythm.
* Tony Iommi plays other cool riffs.
* Ozzy Osbourne sang the chorus.
* Guizer Butler moved to the rhythm of the couplet.
* Tony Iommi gives an incredibly cool solo.
* Tony Iommi plays cool riffs.
* Ozzy Osbourne sang verse number 3.
* Guizer Butler switched to chorus rhythm.
* Tony Iommi plays other cool riffs.
* Ozzy Osbourne sang the chorus.
* Guizer Butler moved to the rhythm of the couplet.
* Tony Iommi plays cool riffs.
* Geizer Butler finishes playing.
*/