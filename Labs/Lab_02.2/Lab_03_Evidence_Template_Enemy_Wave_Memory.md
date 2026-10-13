# Chapter 2 · Practical Lab 3 · Evidence
## Enemy wave memory console

Name or student identifier: [complete]

Date (YYYY-MM-DD): [complete]

Repository URL, if used: [complete / not used]

Visual Studio version: [complete]

Platform Toolset: v145 · Language: C++17 · Configuration: Debug · Platform: x64

---

## How to use this evidence record

Complete this file **while you work through the practical**.

Keep answers short. The practical already supplies the required behaviour and expected output, so you do not need to invent a second test suite or run unsafe memory experiments.

When you make a prediction, write it down before running the code. If the result differs, correct the code or your explanation and continue.

Never deliberately run a double delete, use-after-delete, out-of-bounds access or mismatched `delete`/`delete[]`.

---

## 01 · Project setup

**Project name:**

[complete]

**Files created:**

- [ ] `Main.cpp`
- [ ] `Enemy.h`
- [ ] `Enemy.cpp`
- [ ] `EnemyWave.h`
- [ ] `EnemyWave.cpp`

**Build settings checked:**

- [ ] Platform Toolset `v145`
- [ ] C++ Language Standard `ISO C++17`
- [ ] Warning Level `/W4`
- [ ] `Debug`
- [ ] `x64`

**First successful output:**

```text
Enemy wave memory lab
```

**Did the empty project build and run successfully?**

[yes / no]

If no, briefly record the problem you fixed:

[complete / not applicable]

---

## 02 · One dynamic Enemy

For the single-enemy stage, identify the object and the pointer separately.

**Allocation expression used:**

```cpp
[complete]
```

**Starting health predicted:**

[complete]

**Health after 30 damage predicted:**

[complete]

**Actual output:**

```text
[copy the Single dynamic enemy output here]
```

**Who owns the dynamically allocated Enemy?**

[one sentence]

**Which statement releases that allocation?**

```cpp
[complete]
```

**Why does setting the pointer to `nullptr` not replace the required release?**

[one sentence]

---

## 03 · Raw dynamic Enemy array

The raw-array experiment uses three Enemy objects in one array allocation.

**Array count:**

[complete]

**Prediction before running:**

- Enemy 0 health: [complete]
- Enemy 1 health: [complete]
- Enemy 2 health: [complete]
- Alive enemies: [complete]
- Total health: [complete]

**Actual output:**

```text
[copy the Raw dynamic array output here]
```

**Which cleanup form did you use?**

[complete]

**Why would deleting each element individually be incorrect for this array?**

[one or two sentences]

### Objects versus pointer slots

Complete the statements.

`new Enemy[3]` creates ____________________.

`new Enemy*[3]{}` creates ____________________ and creates ______ Enemy objects.

---

## 04 · EnemyWave ownership

`EnemyWave` stores an `Enemy*` member and owns the array that pointer identifies.

**Accepted wave-count range:**

[complete]

**What happens for `EnemyWave{8}`?**

[one sentence]

**Why is this forward declaration sufficient in `EnemyWave.h`?**

```cpp
class Enemy;
```

[one sentence]

**Why must `EnemyWave.cpp` include `Enemy.h`?**

[one sentence]

**Which allocation is owned by the EnemyWave destructor?**

[one sentence]

**Which cleanup form must the destructor use?**

[complete]

**Why are the copy constructor and copy assignment deleted?**

[one or two sentences]

---

## 05 · EnemyWave behaviour

For:

```cpp
EnemyWave wave{3};

wave.damageEnemy(0, 25);
wave.damageEnemy(1, 100);
wave.damageEnemy(2, 60);
```

**Prediction before running:**

- `count()`: [complete]
- `healthAt(0)`: [complete]
- `healthAt(1)`: [complete]
- `healthAt(2)`: [complete]
- `aliveCount()`: [complete]
- `totalHealth()`: [complete]

**Actual output:**

```text
[copy the Owned wave output here]
```

### Invalid index check

For:

```cpp
wave.damageEnemy(9, 10);
```

**Predicted return value:**

[complete]

**Did the stored health values remain unchanged?**

[yes / no]

**Why must the index be checked before `m_enemies[t_index]` is used?**

[one sentence]

---

## 06 · Invalid wave

**Prediction for `EnemyWave invalid{8}`:**

- count: [complete]
- total health: [complete]
- dynamic Enemy array allocated? [yes / no]

**Actual output:**

```text
[copy the Invalid wave output here]
```

---

## Allocation ledger

Record the three ownership cases used in the practical.

| Allocation | What exists | Owner | Matching release |
|---|---|---|---|
| `new Enemy{}` | [complete] | [complete] | [complete] |
| `new Enemy[enemyCount]` | [complete] | [complete] | [complete] |
| `new Enemy[m_count]` inside `EnemyWave` | [complete] | [complete] | [complete] |

---

## Final console check

Paste your final program output.

```text
[complete]
```

**Does it match the published output in the practical?**

[yes / no]

If no, record the remaining difference:

[complete / not applicable]

---

## Short understanding check

Answer each in one or two sentences.

**1. What is the difference between a pointer variable and the dynamically allocated object it identifies?**

[complete]

**2. Why does `new Enemy[3]` use `delete[]` rather than `delete`?**

[complete]

**3. Why does destroying an `EnemyWave` need to release its array?**

[complete]

**4. Why does the raw pointer type alone not prove who owns the target?**

[complete]

**5. Why is a correct printed value not enough to prove that the lifetime logic is correct?**

[complete]

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

## Optional stretch · `empty()`

Complete only if attempted.

**Did you add `bool empty() const;`?**

[yes / no / not attempted]

**Expected results:**

- `EnemyWave{0}` -> `true`
- `EnemyWave{8}` -> `true`
- `EnemyWave{3}` -> `false`

**Actual results:**

[complete / not attempted]

---

## Final checklist

- [ ] I created the Visual Studio solution and project from scratch.
- [ ] All five source/header files are included in the project.
- [ ] The project builds using v145, C++17, `/W4`, Debug and x64.
- [ ] The single dynamic Enemy is released with `delete`.
- [ ] The raw Enemy array is released with `delete[]`.
- [ ] `EnemyWave` rejects counts outside 0–5 without allocating.
- [ ] `EnemyWave` owns one dynamic Enemy array when its count is positive.
- [ ] `EnemyWave::~EnemyWave()` releases that array using `delete[]`.
- [ ] Every array index is validated before use.
- [ ] Copy construction and copy assignment remain disabled.
- [ ] Temporary boundary-check code has been removed.
- [ ] The final console output matches the practical.
- [ ] The final project builds successfully.

---

## Final note

One ownership or lifetime rule I can now explain without copying the workbook:

[complete]
