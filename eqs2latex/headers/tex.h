#ifndef TEX_H
#define TEX_H
#pragma once

#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <regex>
#include <algorithm>
#include <iostream>

unsigned find1NumberPos(const std::string &str);

std::string convertToLatex(const std::string &input);

std::vector<std::string> splitTerms(const std::string &expression);

std::string processExpression(const std::string &expression);

std::vector<std::string> extractTerms(const std::string &input);

int extractSubscript(const std::string &term);

std::vector<std::string> sortTerms(const std::vector<std::string> &terms);

std::string reconstructOutput(const std::vector<std::string> &sortedTerms);

std::string convert(const std::string &input);

#endif // TEX_H
