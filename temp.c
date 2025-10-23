#include <stdio.h>

static double toC(double v, char s) {
    if (s == 'C' || s == 'c') return v;
    if (s == 'F' || s == 'f') return (v - 32.0) * 5.0 / 9.0;
    return v - 273.15;
}

static double fromC(double c, char t) {
    if (t == 'C' || t == 'c') return c;
    if (t == 'F' || t == 'f') return c * 9.0 / 5.0 + 32.0;
    return c + 273.15;

}

int main(void) {
    double value;
    char inScale, outScale;
    printf("Enter the temperature value: ");
    if (scanf("%lf", &value) != 1) return 0;
    printf("Enter the original scale (C, F, or K): ");
    if (scanf(" %c", &inScale) != 1) return 0;
    printf("Enter the scale to convert to (C, F, or K): ");
    if (scanf(" %c", &outScale) != 1) return 0;
    double inC = toC(value, inScale);
    double converted = fromC(inC, outScale);
    double convC = (outScale == 'C' || outScale == 'c') ? converted
                    : (outScale == 'F' || outScale == 'f') ? toC(converted, 'F')
                    : toC(converted, 'K');
    const char *category;
    const char *advisory;
    if (convC < 0.0) {
        category = "Freezing";
        advisory = "Wear a jacket!";
    } else if (convC < 10.0) {
        category = "Cold";
        advisory = "Layer up.";
    } else if (convC < 25.0) {
        category = "Comfortable";
        advisory = "Have a nice day!";
    } else if (convC < 35.0) {
        category = "Hot";
        advisory = "Drink lots of water!";
    } else {
        category = "Extreme Heat";
        advisory = "Stay indoors.";
    }
    printf("Converted temperature: %.2f %c\n", converted, (outScale >= 'a' ? outScale - 32 : outScale));
    printf("Temperature category: %s\n", category);
    printf("Weather advisory: %s\n", advisory);
    
    return 0;
}