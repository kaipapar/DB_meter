KY-038 dB sensitivity is 49db to 90db

### Electrec sensor: 
#### [Advantages and disadvantages of ECM](https://engineeringproductdesign.com/knowledge-base/guide-to-microphones-in-product-design/)

##### Advantages

- Relatively low cost
- Available in a range of sizes
- Output via a low-noise [JFET buffer](http://www.muzique.com/lab/buffers.htm)
- They are available with solder pads, pins, surface mount and wire lead.
- operating temperature range of -20oC to +70oC

##### Disadvantages

- ECM is unsuitable for the high temperatures involved with the [reflow soldering](https://en.wikipedia.org/wiki/Reflow_soldering) process as it affects the diaphragm.
- The performance, repeatability, and stability of ECMs over temperature and other environmental conditions are poor.

## Initial plan

1. identify sources of type B uncertainty from spec sheet etc
2. Create rig for testing
	- standardize environment
		- temp, sound source, sound source distance
		- how accurate is a phone speaker as a sound source?
3. test dB(Hz) sweeps for multiple different dB levels
	1. also test static signals? Testing harmonics is probably overkill
4. Save test data as separate csv files
	1. select a sampling time eg 5000ms
6. import to matlab
	1. analyze data
5. Identify sources of type A uncertainty
	1. static signal in static environment --> how much uncertainty occurs? 
	2. freq sweeps should show a flat line response. if not:
		1. in which frequencies is the sensor most sensitive? What are the min and max frequencies the sensor recognizes?
6. From powerpoint: timer based triggering: useless in our use case
7. From powerpoint: report testing digital filters for measured data:
	1. implement digital filter to make sensor response flatter over temp, frequency and dB
	2. Have to do RT filtering, check the timing with picoscope through gpio pins
		1. try to push the microcontroller?
		2. see what kind of sample rate can be achieved without siming error?
8. Summary of learning achievements
