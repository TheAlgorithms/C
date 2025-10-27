# Convolution

## Understanding Convolution

### What Is Convolution?
Convolution is simple, but how it works looks a little tricky but not something you would never understand.
An application with which most of us are familiar will make it easy,Imagine you have a recording of someone 
speaking,but there’s background noise — maybe static or hum from a fan.
If you plot the audio signal, it’s just a long 1D waveform (amplitude vs. time). The unwanted noise appears 
as rapid, random fluctuations on top of the smooth speech waveform.

To reduce this noise, we can apply a low-pass filter — a small sequence of numbers (a kernel) that emphasizes 
slow changes (speech patterns) and suppresses fast, noisy changes.

Here’s what happens during convolution:

You slide this filter across the audio signal.

At each step, you multiply the overlapping values and sum them up.

The resulting output is a smoothed version of the signal, where random high-frequency noise has been reduced.

Mathematically, the convolution operation combines nearby samples in a way that averages out the unwanted 
fluctuations while keeping the overall structure intact.
That’s why convolution is widely used in digital signal processing — to filter out noise, enhance features, or 
detect specific patterns (like beats or speech cues).
This is an example for the one dimenstional convolution we will try to implement the basic implementation which looks
mathematically daunting but it's cakewalk if you understand the implementation

### Project setup
The C code I provided will walk you through the implementation 
feel free to clone this repository and try to code this up by yourself 
```
git clone https://github.com/depuc/Convolution.git
```
set up your Python environment (if required):
```
python3 -m venv venv
source venv/bin/activate
```
Then install the required packages
```
pip install -r requirements.txt
```
once everything is setup you can directly run the compiled binary
```
conv
```
Tweak the code, try out floating numbers get creative.

