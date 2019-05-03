/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};
    ConstantChooser c321{"321"}, c12{"12"}, c11111{"11111"}, c8{"8"}, cnull{"null"};
    ConstantGuesser g0{"0"}, g52{"52"},g43{"43"}, g88888888{"88888888"}, g1{"1"}, gnull{"null"};
		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4") ;     // 0 bull, 4 pgia
		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("7219","7219"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","6789"), "0,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1567"), "1,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1256"), "2,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1235"), "3,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","7289"), "1,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","6239"), "2,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","6734"), "2,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","2569"), "0,1")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","2109"), "0,2")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","2153"), "0,3")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","2539"), "0,1")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","5209"), "1,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","2222"), "1,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1321"), "1,2")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","2153"), "0,3")
		.CHECK_THROWS(calculateBullAndPgia("task","cs"))
		.CHECK_THROWS(calculateBullAndPgia("ts","1234"))
		.CHECK_THROWS(calculateBullAndPgia("1234","task"))
		.CHECK_OUTPUT(calculateBullAndPgia("7777","7777"), "4,0")
		.CHECK_OUTPUT(calculateBullAndPgia("3309","2209"), "2,0")
		.CHECK_THROWS(calculateBullAndPgia("","2153"))
		.CHECK_THROWS(calculateBullAndPgia("1111",""))
    .CHECK_THROWS(calculateBullAndPgia("",""));
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c8, g0, 1, 101), 1) 
		.CHECK_EQUAL(play(c8, g43, 1, 101), 1)
		.CHECK_EQUAL(play(c8, g43, 2, 100), 0)
		.CHECK_EQUAL(play(c8, g88888888, 1, 100), 101)
		.CHECK_EQUAL(play(c8, g88888888, 7, 100), 0) 
		.CHECK_EQUAL(play(c8, g1, 1, 100), 1)
		.CHECK_EQUAL(play(c8, g1, 2, 100), 0)
    .CHECK_EQUAL(play(c8, g43, 3, 100), 0) 

		
		
		.CHECK_EQUAL(play(c321, g52, 3, 100), 101) 
		.CHECK_EQUAL(play(c321, g0, 1, 100), 0) 
		.CHECK_EQUAL(play(c321, g52, 3, 100), 101)
		.CHECK_EQUAL(play(c321, g52, 2, 100), 0)
		.CHECK_EQUAL(play(c321, g88888888, 3, 100), 101)
		.CHECK_EQUAL(play(c321, g88888888, 7, 100), 0) 
		.CHECK_EQUAL(play(c321, g1, 3, 100), 101)
		.CHECK_THROWS(play(c1234, gnull, 2, 100))
		.CHECK_THROWS(play(cnull, g52, 3, 100)) 
    .CHECK_THROWS(play(cnull, gnull, 2, 100));
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=10, true);  // smarty should always win in at most 10 turns!
		}

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}

