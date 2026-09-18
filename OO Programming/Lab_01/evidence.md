# Practical Lab 1 — evidence

Repository URL:
Final commit identifier: submit separately if adding it here would create a new commit.
Build configuration:
Known unfinished requirements:

## A — Structure and diagnosis

| Fault | First useful diagnostic | Stage and cause | Repair | Verified result |
| --- | --- | --- | --- | --- |
| 1 | | | | |
| 2 | | | | |

Build explanation (maximum 80 words):

## B — Input recovery

Explain the different jobs of state reset and input removal (two sentences):

## D — Pointer trace

Use observed address values or symbolic labels that identify the same objects consistently.

| State | totalStock | availableStock | dispatchCount | Selected object | Stored pointer value | Pointer's own address | Dereferenced value, if valid |
| --- | --- | --- | --- | --- | --- | --- | --- |
| Before stock update | | | | | | | |
| After stock update | | | | | | | |
| After retargeting/increment | | | | | | | |
| After null reset | | | | | | | Not evaluated |

Explain selectedQuantity, *selectedQuantity and &selectedQuantity:
Explain ownership and why non-null is not a universal safety guarantee:

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
