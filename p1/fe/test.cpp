#include <iostream>
using namespace std;

int main() {
	char text[] = "boogas is an amazing countr source";
	int firstWordLength = 0, wordBeforeLastLength = 0, lastWordLength = 0;
	int wordBeforeLastIndex = -1;

	int spaceCount = 0;
	for (int i = 0; text[i] != '\0'; i++) {
		if (text[i] == ' ') {
			spaceCount++;
		}
	}

	int currentSpaceCount = 0;
	for (int i = 0; text[i] != '\0'; i++) {
		if (text[i] == ' ') {
			currentSpaceCount++;
		}
		else {
			if (currentSpaceCount == 0) {
				firstWordLength++;
			}
			else if (currentSpaceCount == spaceCount - 1) {
				wordBeforeLastLength++;
				if (wordBeforeLastIndex == -1) {
					wordBeforeLastIndex = i;
				}
			}
			else if (currentSpaceCount == spaceCount) {
				lastWordLength++;
			}
		}
	}

	int leftShiftDistance = wordBeforeLastIndex - firstWordLength / 2;
	int rightShiftDistance = (wordBeforeLastIndex + wordBeforeLastLength + 1 + lastWordLength / 2) - (wordBeforeLastIndex + wordBeforeLastLength / 2);

	int wbllCopy = wordBeforeLastIndex;
	for (int i = 0; i < leftShiftDistance; i++) {
		for (int k = wordBeforeLastIndex; k < wordBeforeLastIndex + wordBeforeLastLength / 2; k++) {
			char copy = text[k - 1];
			text[k - 1] = text[k];
			text[k] = copy;
		}
		wordBeforeLastIndex--;
	}

	for (int i = 0; i < rightShiftDistance - wordBeforeLastLength / 2; i++) {
		int c = 0;
		for (int k = wbllCopy + wordBeforeLastLength-1; k > wbllCopy + wordBeforeLastLength / 2-1; k--) {
			c++;
			char copy = text[k + 1];
			text[k + 1] = text[k];
			text[k] = copy;
		}
		cout << c << endl;
		wbllCopy++;
	}

	cout << text;
}