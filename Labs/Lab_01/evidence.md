# Practical Lab 1 — evidence

Repository URL:https://github.com/kristianbelchev06/OO-Programming.git
Final commit identifier: submit separately if adding it here would create a new commit.
Build configuration:
Known unfinished requirements:E

## A — Structure and diagnosis

| Fault | First useful diagnostic | Stage and cause | Repair | Verified result |
| --- | --- | --- | --- | --- |
| 1 | | | | |
| 2 | | | | |

Build explanation (maximum 80 words):
Dispatch.h declares Dispatch::printHeading() and dispatch.cpp provides its definition. Main.cpp includes the header and Dispatch::printHeading(), which makes the link connect the definition.

## B — Input recovery

Explain the different jobs of state reset and input removal (two sentences): Resetting the stream allows it to be used again after a wrong answer has been put in. And after fixing the numbers or characters for then next answer it runs without a problem.

## D — Pointer trace

Use observed address values or symbolic labels that identify the same objects consistently.

| State | totalStock | availableStock | dispatchCount | Selected object | Stored pointer value | Pointer's own address | Dereferenced value, if valid |
| --- | --- | --- | --- | --- | --- | --- | --- |
| Before stock update |40 | 40| 0| availableStock| &availableStock|selectedQuantity | 40|
| After stock update | 40| 15| 0| availableStock| &availableStock| selectedQuantity| 15|
| After retargeting/increment | 40| 15| 1| dispatchCount| &dispatchCount|selectedQuantity | 1|
| After null reset | 40| 15| 1| none|nullptr | selectedQuantity| Not evaluated |

Explain selectedQuantity, *selectedQuantity and &selectedQuantity: Selected Quantity stores the adress that is pointed to. *selectedQuantity access that adress and &selectedQuantity gives the adress.
Explain ownership and why non-null is not a universal safety guarantee: It doesnt own the onjects because it only points to  variables that exist and doesnt create or delete any.

## E — Tests

Record predictions before running. Do not claim a test passed unless you ran it.

| ID | Input/data | Expected | Actual/exit status | Pass/fail | Interpretation |
| --- | --- | --- | --- | --- | --- |
| P1 | | | | | |
| P2 | | | | | |
| P3 | | | | | |
| P4 | | | | | |
| P5 | | | | | |
| P6 | | | | | |
| P7 | | | | | |
| P8 — own case | | | | | |

Why does the extra test detect something the baseline does not?

Final baseline restored:
Both projects build / recorded limitations:
Source snapshot and evidence submitted:
