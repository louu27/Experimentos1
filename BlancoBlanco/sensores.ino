void calibra() {

  for (int i = 0; i < 150; i++) {

    sigueLineas.calibrate();

    delay(10);
  }
  for (int i = 0; i < SensorCount; i++) {
    umbralValues[i] = ((sigueLineas.calibrationOn.minimum[i] + sigueLineas.calibrationOn.maximum[i]) / 2) + toleranciaUmbral;
  }
}