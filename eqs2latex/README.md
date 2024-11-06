<div align="center">
  <h1><b>Code Documentation</b></h1>
</div>

## Overview

> This C++ code provides functions for converting symbolic (strings) expressions 
of dynamic equations into LaTeX format. 

`Main functionalities:`
- Handle 1° & 2° order derivatives, special characters (ex: Greek letters), Latin variables, numerics constant, sub & superscripts.
- Includes sorting capabilities of terms based on their derivative order. 

The main function `convert` processes an input expression and outputs a formatted LaTeX string.

## Functions

### `find1NumberPos`

> **Description**:  
Finds the position of the first non-digit character in a string when scanning backwards. This is useful for identifying subscripts in expressions, preventing undesirable front-numbers detection.

**Parameters**:
- `const std::string &str`: input string, which to find the position from.

**Returns**:

- Unsigned index of the first non-digit character right before the subscript begins, or `0` if all characters are digits.
 

### `convertToLatex`

> **Description**:  
Converts a given string representing a mathematical term into its LaTeX representation. It handles derivatives, special characters, and formatting for subscripts & superscripts.

**Parameters**:
- `const std::string &input`: input string to be converted.

**Returns**:
- A LaTeX formatted string.


### `splitTerms`

> **Description**: 
Splits a mathematical expression into terms or individual element using regex to match `-`, `+`, `*`, `=`, `==`, `0` operators as delimiters.

**Parameters**:
- `const std::string &expression`: input expression to split.

**Returns**:
- A vector of strings, each one representing a term from the expression.


### `processExpression`

> **Description**:  
Handles the processing of each individual term.

**Parameters**:
- `const std::string &expression`: input expression to be processed.

**Called functions**:

- `convertToLatex`

- `splitTerms`

**Returns**:
- A string representing the processed LaTeX output.


### `extractTerms`

> **Description**:  
Extracts terms from an input expression using regex to identify  `+`, `-` operators as delimiters.

**Parameters**:
- `const std::string &input`: input expression, which to extract terms from.

**Returns**:
- A vector of strings containing the extracted terms.


### `extractSubscript`

> **Description**:  
Extracts the numeric subscript from a term, if present. 

**Parameters**:
- `const std::string &term`: term which to extract the subscript from.

**Returns**:
- The subscript as an integer, or `-1` if no subscript is found.


### `sortTerms`

> **Description**:  
Sorts a vector of terms based on their derivative order and numeric subscripts (highest to lowest).

**Parameters**:
- `const std::vector<std::string> &terms`: terms to sort.

**Returns**:
- A sorted vector of string terms.


### `reconstructOutput`

> **Description**:  
Reconstructs a final string from sorted terms, ensuring to concatenate them properly with the corresponding original operators.

**Parameters**:
- `const std::vector<std::string> &sortedTerms`: vector of sorted terms to perform the final reconstruction.

**Returns**:
- A string representing the reconstructed output.


### `convert`

> **Description**:  
Gtest-function call for performing the complete flow of input processing. It converts it to LaTeX format, splits the output into equation's LHS & RHS, and extracts the terms to accomplish sorting.
    
**Parameters**:
- `const std::string &input`: The input expression to convert.

**Returns**:
- A string representing the complete LaTeX formatted output.


## Usage Example

- See `main.cpp` for comprehensive & detailed outputs steps, or `test.cpp` otherwise.
