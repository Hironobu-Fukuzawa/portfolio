from hashlib import new
import matplotlib.pyplot as plt
#This is not a good habit to declare global variables like this
#But just for our class assignments, let's do this at the moment
original_wave_sample = [0, 3, 7, 14, 18, 24, 23, 29, 28, 30, 32, 35, 31, 34, 32, 30, 25, 25, 24, 23, 18, 14, 15, 14, 12, 12, 7, 8, 10, 9, 5, 8, 8, 8, 8, 5, 6, 4, 2, 2, 3, -1, -5, -4, -9, -9, -14, -16, -17, -18, -23, -24, -25, -25, -23, -20, -20, -16, -17, -11, -7, -7, 0, 3, 6, 8, 15, 18, 19, 24, 27, 24, 28, 25, 29, 27, 26, 22, 20, 16, 13, 13, 11, 7, 4, 0, 0, 0, 0, -3, -6, -6, -7, -6, -5, -7, -6, -6, -6, -6, -7, -9, -13, -11, -17, -16, -22, -24, -23, -27, -29, -30, -34, -33, -34, -37, -34, -32, -33, -28, -28, -23, -18, -13, -10, -8, 0, 3, 10, 12, 15, 22, 22, 27, 29, 31, 31, 29, 31, 27, 26, 27, 24, 20, 17, 17, 14, 11, 12, 8, 6, 5, 8, 6, 3, 6, 7, 4, 7, 6, 7, 6, 5, 4, 2, 0, -2, -3, -6, -7, -12, -14, -16, -15, -18, -21, -22, -23, -26, -26, -22, -23, -21, -18, -13, -9, -8, -3, -1, 6, 10, 12, 17, 20, 23, 25, 28, 30, 30, 30, 27, 25, 26, 24, 19, 18, 17, 12, 12, 8, 7, 4, 0, -2, -2, -1, -1, -6, -4, -4, -3, -5, -7, -8, -5, -5, -7, -10, -10, -12, -17, -17, -22, -21, -25, -29, -29, -32, -35, -34, -32, -33, -33, -33, -33, -28, -24, -22, -18, -15, -9, -6, 0, 6, 9, 11, 16, 22, 22, 24, 25, 29, 30, 31, 28, 29, 27, 22, 22, 20, 16, 17, 15, 14, 10, 10, 6, 8, 4, 4, 7, 4, 7, 7, 6, 6, 3, 7, 2, 2, 4, 1, 0, -2, -3, -7, -8, -13, -14, -16]

for i in range(len(original_wave_sample)):
    original_wave_sample[i]*=1000

# wave = original_wave_sample
new_wave = original_wave_sample

def filter_wave(wave, times):
    new_wave = wave.copy()
    for j in range(times):
        pre_wave = new_wave.copy()
        for i in range(len(new_wave)):
            first_val = 0 if i == 0 else pre_wave[i-1]
            last_val = 0 if i + 1 == len(pre_wave) else pre_wave[i+1]
            new_wave[i] = int(first_val * 0.2 + pre_wave[i] * 0.6 + last_val * 0.2)
    return new_wave

def filter_wave_recursive(wave, times):
    new_wave = wave.copy()
    if times < 1:
        return new_wave
    for i in range(len(new_wave)):
        first_val = 0 if i == 0 else new_wave[i-1]
        last_val = 0 if i + 1 == len(new_wave) else new_wave[i+1]
        new_wave[i] = int(first_val * 0.2 + new_wave[i] * 0.6 + last_val * 0.2)
    return filter_wave(new_wave.copy(), times - 1)

new_wave = filter_wave(original_wave_sample, 5)
plt.plot(new_wave)
plt.show()

# def filter_wave(wave, times):
#     new_wave = wave.copy()
#     if times < 1:
#         return new_wave
#     for i in range(len(new_wave)):
#         first_index = 0 if i == 0 else i - 1
#         last_index = 0 if i + 1 == len(new_wave) else i + 1
#         new_wave[i] = int(new_wave[first_index] * 0.2) + int(new_wave[i] * 0.6) + int(new_wave[last_index] * 0.2)
#     return filter_wave(new_wave, times - 1)