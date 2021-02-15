#pragma once
#include <inttypes.h>

class AXP192 {
public:
  enum CHGCurrent {
    kCHG_100mA = 0,
    kCHG_190mA,
    kCHG_280mA,
    kCHG_360mA,
    kCHG_450mA,
    kCHG_550mA,
    kCHG_630mA,
    kCHG_700mA,
    kCHG_780mA,
    kCHG_880mA,
    kCHG_960mA,
    kCHG_1000mA,
    kCHG_1080mA,
    kCHG_1160mA,
    kCHG_1240mA,
    kCHG_1320mA,
  };

  AXP192();
  void begin();
  void ScreenBreath(uint8_t brightness);
  bool GetBatState();

  void EnableCoulombcounter(void);
  void DisableCoulombcounter(void);
  void StopCoulombcounter(void);
  void ClearCoulombcounter(void);
  uint32_t GetCoulombchargeData(void);
  uint32_t GetCoulombdischargeData(void);
  float GetCoulombData(void);
  void PowerOff(void);
  void SetAdcState(bool state);
  // -- sleep
  void PrepareToSleep(void);
  void RestoreFromLightSleep(void);
  void DeepSleep(uint64_t time_in_us = 0);
  void LightSleep(uint64_t time_in_us = 0);
  uint8_t GetWarningLeve(void);

  bool ShortButonPress();
  void SetShortButtonPressTime(uint8_t setting);

public:
  // void SetChargeVoltage( uint8_t );
  // void SetChargeCurrent( uint8_t );
  float GetBatVoltage();
  float GetBatCurrent();
  float GetVinVoltage();
  float GetVinCurrent();
  float GetVBusVoltage();
  float GetVBusCurrent();
  float GetTempInAXP192();
  float GetBatPower();
  float GetBatChargeCurrent();
  float GetAPSVoltage();
  float GetBatCoulombInput();
  float GetBatCoulombOut();
  uint8_t GetWarningLevel(void);
  void SetCoulombClear();
  void SetLDO2(bool State);
  void SetDCDC3(bool State);

  uint8_t AXPInState();
  bool isACIN();
  bool isCharging();
  bool isVBUS();

  void SetLDOVoltage(uint8_t number, uint16_t voltage);
  void SetDCVoltage(uint8_t number, uint16_t voltage);
  void SetESPVoltage(uint16_t voltage);
  void SetLcdVoltage(uint16_t voltage);
  void SetLDOEnable(uint8_t number, bool state);
  void SetLCDRSet(bool state);
  void SetBusPowerMode(uint8_t state);
  void SetLed(uint8_t state);
  void SetSpkEnable(uint8_t state);
  void SetCHGCurrent(uint8_t state);

private:
  void Write1Byte(uint8_t Addr, uint8_t Data);
  uint8_t Read8bit(uint8_t Addr);
  uint16_t Read12Bit(uint8_t Addr);
  uint16_t Read13Bit(uint8_t Addr);
  uint16_t Read16bit(uint8_t Addr);
  uint32_t Read24bit(uint8_t Addr);
  uint32_t Read32bit(uint8_t Addr);
  void ReadBuff(uint8_t Addr, uint8_t Size, uint8_t *Buff);
};
