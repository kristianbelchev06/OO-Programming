# Chapter 2 · Practical Lab 2 · Evidence
## Beacon pool console

Name or student identifier: Kristian Belchev[complete]

Date (YYYY-MM-DD): 10/12/2026[complete]

Repository URL, if used: https://github.com/kristianbelchev06/OO-Programming.git[complete / not used]

Visual Studio version: [complete]

Platform Toolset: v145 · Language: C++17 · Configuration: Debug · Platform: x64

---

## How to use this evidence record

Complete this file **while you work through the lab**.

Keep answers short. You do not need to invent a separate test suite, use `assert`, or create extra screenshots. The practical already gives you the calls and expected console results needed for the core checks.

When the lab asks for a prediction, write it down before you run the program. If your prediction is wrong, correct the code or your explanation and continue.

---

## 01 · Project setup

**Project name:**
BeaconPoolLab
[complete]

**Files created:**

- [ ] `Main.cpp`
- [ ] `Beacon.h`
- [ ] `Beacon.cpp`
- [ ] `Receiver.h`
- [ ] `Receiver.cpp`
- [ ] `BeaconPool.h`
- [ ] `BeaconPool.cpp`

**Build settings checked:**

- [ ] Platform Toolset `v145`
- [ ] C++ Language Standard `ISO C++17`
- [ ] Warning Level `/W4`
- [ ] `Debug`
- [ ] `x64`

**First successful console output:**

```text
Beacon pool lab
```

**Did the starter project build and run successfully?**

[yes / no]
yes 
If no, briefly record the problem you fixed:

[complete / not applicable]

---

## 02 · Receiver and Beacon

The receiver uses a `Beacon const&` parameter but does not contain a `Beacon` by value.

**Why is this enough in `Receiver.h`?**

```cpp
class Beacon;
```

[one sentence] The declaration tells the compiler that Beacon is a class, and Receiver uses it with a const refference.

**Which files did you include in `Receiver.cpp` before calling `t_beacon.x()`?**

[complete] Receiver.h and Beacon.h.

**Prediction before running:** 25

A receiver at 35 and a beacon at 10 should have range: [complete]

**Actual output:** Connection check
Range to beacon: 25

```text
[copy the Connection check output here]
```

**Status:**

[not started / working / complete]
complete
---

## 03 · BeaconPool composition

`BeaconPool` contains:

```cpp
Beacon m_beacons[CAPACITY];
```

**Why does `BeaconPool.h` need the complete `Beacon` definition rather than only a forward declaration?**

[one or two sentences] Because the array stores complete Beacon objects by value, so the compiler needs to know  the size and layout

**What does this declaration permit?**

```cpp
friend class BeaconPool; 
```

[one sentence]It allows BeaconPool to access Beacon's private members and functions.

**Does friendship itself make `BeaconPool` own a `Beacon`?**

[yes / no, followed by one short explanation] No. Friendship grants access to private members but does not create ownership.

**Status:**

[not started / working / complete]
complete
---

## 04 · Request logic

For a valid request, the pool should activate the first free slot.

### Published sequence

**My prediction before running:**

- request 30 -> slot [complete]0
- request 60 -> slot [complete]1
- request 90 -> slot [complete]2
- request 50 when full -> slot [complete] -1

**Actual values:**

- request 30 -> slot [complete]0
- request 60 -> slot [complete]1
- request 90 -> slot [complete]2
- request 50 when full -> slot [complete]-1

**What range of signal strengths does your `request()` accept?**

[complete]It accepts strengths from 1 to 100 inclusive.

**When should `s_successfulRequests` increase?**

[one sentence]It increases only after a request successfully activates a free Beacon slot.

**Status:**

[not started / working / complete]
complete
---

## 05 · Release and reuse

The core sequence releases the second checkout and then requests a new strength of 75.

**Prediction before running:**

- released slot: [complete]1
- released result: [complete] true
- strength after release: [complete]0
- reused slot: [complete]1

**Actual result:**

```text
[copy the Release and reuse output here]

Release and reuse
Released slot 1: true
Strength after release: 0
Request 75 -> slot 1
Active beacons: 3
Successful requests: 4
```

**Why does `reset()` clear the strength as well as the active flag?**

[one sentence] It clears the old signal so the released Beacon isnt stale.

**Why must `release()` validate the index before accessing the array?**

[one sentence] to avoid undefined behaviour

**Status:**

[not started / working / complete]complete

---

## 06 · Per-object state and shared state

Before running the second-pool experiment, complete the predictions.

**Pool B starts with active count:**

[complete]0

**Its first successful request should use slot:**

[complete]0

**Should using Pool B change Pool A's active count?**

[complete]5

**Expected shared successful-request tally after the Pool B request:**

[complete]No. Pool A and Pool B have separate arrays.

**Actual output:**

```text
[copy the Pool B output here]Pool B
Pool B active: 0
Pool B request 25 -> slot 0
Pool A active: 3
Pool B active: 1
Successful requests: 5
```

Complete the statements:

`m_beacons` is ___per object______ state because each `BeaconPool` object has its own array.

`s_successfulRequests` is _____shared class wide_____ state because every `BeaconPool` object refers to the same tally.

---

## 07 · Boundary check

Use a fresh `BeaconPool` and temporarily request strength `0`.

**Prediction:**

- returned slot: [complete] -1
- active count afterwards: [complete] 0 
- should the shared tally increase? [complete] No

**Actual result:**

[complete]returned slot: -1
active count afterwards: 0
should the shared tally increase? No

Restore the final `Main.cpp` afterwards.

---

## Final console check

Your final output should match the practical:

```text
Beacon pool lab

Connection check
Range to beacon: 25

Pool A
Start active: 0
Request 30 -> slot 0
Request 60 -> slot 1
Request 90 -> slot 2
Request 50 -> slot -1
Active beacons: 3
Successful requests: 3

Release and reuse
Released slot 1: true
Strength after release: 0
Request 75 -> slot 1
Active beacons: 3
Successful requests: 4

Pool B
Pool B active: 0
Pool B request 25 -> slot 0
Pool A active: 3
Pool B active: 1
Successful requests: 5
```

**Paste your final console output below:**

```text
[complete]
``` Beacon pool lab

Connection check
Range to beacon: 25

Pool A
Start active: 0
Request 30 -> slot 0
Request 60 -> slot 1
Request 90 -> slot 2
Request 50 -> slot -1
Active beacons: 3
Successful requests: 3

Release and reuse
Released slot 1: true
Strength after release: 0
Request 75 -> slot 1
Active beacons: 3
Successful requests: 4

Pool B
Pool B active: 0
Pool B request 25 -> slot 0
Pool A active: 3
Pool B active: 1
Successful requests: 5

**Does it match?**

[yes / no]
yes
If no, record the remaining difference:

[complete / not applicable]

---complete

## Short understanding check

Answer each in one or two sentences.

**1. Why can `Receiver.h` forward-declare `Beacon`?**

[complete] Because it uses Beacon as a const refference and doesnt store it by value

**2. Why can `BeaconPool.h` not use only the same forward declaration for its array?**

[complete] It grants BeaconPool access to Beacon's private members, but it does not create ownership.

**3. What does `friend class BeaconPool;` grant, and what does it not grant?**

[complete] Every object  has their own m_beacons array so they are not dependent on one another.

**4. Why are `poolA` and `poolB` independent even though they use the same class?**

[complete]Each object owns its own m_beacons array, so their active Beacon states are independent.

**5. Why can `successfulRequests()` be called using `BeaconPool::successfulRequests()`?**

[complete]Because it is a static member function that belongs to the class rather than an individual object.

---

## One problem I fixed

Complete this only if you encountered a genuine problem.

**What went wrong?**

[complete / no problem recorded]

**What did I change?**

[complete / not applicable]

**What happened after rebuilding?**

[complete / not applicable]

Do not invent an error if you did not encounter one.

---

## Optional stretch · `full()`

Complete only if attempted.

**Did you add `bool full() const;`?**

[yes / no / not attempted]

**Expected results:**

- new pool: `false`
- after three successful requests: `true`
- after one release: `false`

**Actual results:**

[complete / not attempted]

---

## Final checklist

- [x ] I created the solution and project from scratch.
- [ x] All seven source/header files are included in the project.
- [ x] The project builds with v145, C++17, `/W4`, Debug and x64.
- [ x] `Receiver.h` uses a forward declaration of `Beacon`.
- [ x] `Receiver.cpp` includes the complete `Beacon` definition before calling Beacon members.
- [ x] `BeaconPool.h` includes `Beacon.h` because it stores Beacon objects by value.
- [x ] `request()` validates strength, uses the first free slot and returns `-1` when it cannot serve a request.
- [x ] `release()` validates the index and resets released state.
- [ x] `activeCount()` reports the state of one pool only.
- [ x] `successfulRequests()` reports the shared class-wide tally.
- [ x] My final console output matches the practical.
- [ x] Temporary boundary-check edits have been restored.
- [ x] The final project builds successfully.

---

## Final note

One class-relationship concept I can now explain without copying the workbook:

[complete] I can differentiate per_object states and  shared static states
