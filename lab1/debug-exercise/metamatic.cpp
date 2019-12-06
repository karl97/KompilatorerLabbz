// ------------------------------------------
// File metamatic.cc
// ------------------------------------------

#include <string>
#include <iostream>

#include "a.h"
#include "abc.h"
#include "abscissa.h"
#include "absurdum.h"
#include "ack.h"

// ------------------------------------------

int main() {
  std::cout << "Starting metamatic...\n";
  int* ty = new int(1);
  std::string tydligen("tyska");
  int tysk = allihop(ty, tydligen);
  int u(1);
  std::string* udd = new std::string("udde");
  int* udda = advent(u, udd);
  int* uggla = new int(0);
  std::string ugn("undan");
  std::string* umgicks = annonsering(uggla, ugn);
  int* undantagandes = new int(1);
  std::string underavdelning("understrykning");
  int underfund = anslutning(undantagandes, underavdelning);
  int understundom(1);
  std::string* undervisning = new std::string("unge");
  std::string ungdom = alias(understundom, undervisning);
  int uppackning(1);
  std::string* uppblandning = new std::string("uppdragsformulering");
  int* uppdelning = allmoge(uppackning, uppblandning);
  int uppe(1);
  std::string* uppenbarligen = new std::string("uppfinning");
  int* uppfattning = ann(uppe, uppenbarligen);
  int* uppfinningsrikedom = new int(0);
  std::string uppgradering("uppkoppling");
  int upphandling = anslutningspropp(uppfinningsrikedom, uppgradering);
  int upplaga(1);
  std::string* upplysning = new std::string("upprepning");
  int* uppmaning = anskaffning(upplaga, upplysning);
  std::cout << "Metamatic finished!\n";
  return 0;
} // main
