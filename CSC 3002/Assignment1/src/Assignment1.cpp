/*
 * File: Assignment1.cpp
 * ----------------------
 * call for each function (of each problem) that you have finished 
 * please do not modify the main function
 */

#include <iostream>
#include "console.h"
#include "Assignment1.h"
using namespace std;

/*
 * Below is the testing part, 
 * you can use it for your testing
 * but do not delete it
 */

int TestCombinatorics() {
  /* TODO */
  /* You can test your implemented function here*/
  cout << permutations(5, 2) << endl;
  cout << combinations(5, 2) << endl;
  return 0;
}

int TestFindDNAMatch() {
  /* TODO */
  /* You can test your implemented function here */
  findAllMatches("AGC", "ACGTTTATGTCGTCAATCGGCAGGGGGAACCCTTTT");
  return 0;
}

int TestRemoveComments() {
  /* TODO */
  /* You can test your implemented function here */

  return 0;
}

int TestBanishLetters() {
  /* TODO */
  /* You can test your implemented function here */
  BanishLetters();
  return 0;
}

int main() {
  cout << "Problem 1:" << endl;
  TestCombinatorics();
  cout << "Problem 2:" << endl;
  TestFindDNAMatch();
  cout << "Problem 3:" << endl;
  TestRemoveComments();
  cout << "Problem 4:" << endl;
  TestBanishLetters();
  return 0;
}
