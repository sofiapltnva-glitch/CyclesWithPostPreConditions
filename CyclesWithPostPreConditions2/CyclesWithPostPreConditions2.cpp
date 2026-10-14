/*******************************
* Платонова Софья              *
* Циклы с пост- и предусловием *
* Вариант 22                   *
* *****************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  double startFrequency = 10.0;
  double changeFrequency = 20.0;
  double finishFrequency = 24.0;
  double firstStep = 2.5;
  double secondStep = 1.0;

  double naturalFrequency;
  double frequency;
  double frequencyRatio;
  double delayTime;
  int stepIndex;

  cout << "Enter natural frequency (Hz): ";
  cin >> naturalFrequency;

  int decimalPlaces = 2;
  cout << fixed << setprecision(decimalPlaces);

  int columnWidth = 16;
  cout << setw(columnWidth) << "Frequency (Hz)"
       << setw(columnWidth) << "Time (ms)" << '\n';

  stepIndex = 0;
  frequency = startFrequency;

  do {
    frequencyRatio = frequency / naturalFrequency;
    delayTime = 2000.0 / (naturalFrequency * sqrt(1.0 - frequencyRatio * frequencyRatio));

    int columnWidth = 16;
    cout << setw(columnWidth) << frequency
         << setw(columnWidth) << delayTime << '\n';

    ++stepIndex;
    frequency = startFrequency + stepIndex * firstStep;
    } while (frequency <= changeFrequency);

    stepIndex = 1;
    frequency = changeFrequency + stepIndex * secondStep;

    while (frequency <= finishFrequency) {
      frequencyRatio = frequency / naturalFrequency;
      delayTime = 2000.0 / (naturalFrequency * sqrt(1.0 - frequencyRatio * frequencyRatio));

      int columnWidth = 16;
      cout << setw(columnWidth) << frequency
           << setw(columnWidth) << delayTime << '\n';

      ++stepIndex;
      frequency = changeFrequency + stepIndex * secondStep;
    }

    return 0;
}