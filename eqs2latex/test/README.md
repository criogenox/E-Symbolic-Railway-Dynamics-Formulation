<div align="center">
  <h1><b>Test Code Documentation</b></h1>
</div>

## Overview

This C++ test file utilizes Google Test/Mock to validate the efficacy of the expression conversion functions defined in the `tex.h` header file. It includes unit tests for global flow conversion, and also individual functions tests to catch the error in intermediates steps.


## Tests

### `TEST(ConvertToLatexTest, FullConversion)`

> **Description**: 
Testing process for the complete LaTeX conversion flow.

### `TEST(ProcessExpressionTest, HandleExpressions)`

> **Description**: 
Verifies the splitting funcionality (`splitTerms`) and the individual LaTeX conversion (`convertToLatex`)

### `TEST(ExtractTermsTest, FullExtraction)`

> **Description**: 
Tests the `extractTerms` function to ensure the appropiate extraction of the terms.

### `TEST(SortTermsTest, OrderSorting)`

> **Description**: 
Validates the `sortTerms` function to guarantee the sorting process according to derivative order and subscripts.

### `TEST(ReconstructOutputTest, TermsReconstruction)`

> **Description**: 
Tests the final reconstruction step (`reconstruct Output`) to verify the perfect assembling of the sorted terms vector.
