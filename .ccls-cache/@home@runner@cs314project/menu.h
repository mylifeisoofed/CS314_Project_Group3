#pragma once
#include "table.h"

struct Service {
  string code;
  string description;
  double cost;
};

void provider_terminal(Table<Member> &members, Table<Provider> &providers);
void manager_terminal();
void check_in(Table<Member> &members, Table<Provider> &providers);
vector<string> split(const string &s, char delimiter);
Service find_service(const string &target);
void display_providers();
void display_providers();