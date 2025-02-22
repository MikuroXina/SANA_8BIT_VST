#include "SynthParameters.h"

namespace {
const float MIN_DELTA = 0.0001f;
}  // namespace

ChipOscillatorParameters::ChipOscillatorParameters(
    AudioParameterChoice* oscWaveType, AudioParameterFloat* volumeLevel,
    AudioParameterFloat* attack, AudioParameterFloat* decay,
    AudioParameterFloat* sustain, AudioParameterFloat* release, 
    AudioParameterChoice* colorType, AudioParameterFloat* colorDuration)
    : OscWaveType(oscWaveType),
      VolumeLevel(volumeLevel),
      Attack(attack),
      Decay(decay),
      Sustain(sustain),
      Release(release), 
      ColorType(colorType),
      ColorDuration(colorDuration){
}

void ChipOscillatorParameters::addAllParameters(AudioProcessor& processor) {
  processor.addParameter(OscWaveType);
  processor.addParameter(VolumeLevel);
  processor.addParameter(Attack);
  processor.addParameter(Decay);
  processor.addParameter(Sustain);
  processor.addParameter(Release);
  processor.addParameter(ColorType);
  processor.addParameter(ColorDuration);
}

void ChipOscillatorParameters::saveParameters(XmlElement& xml) {
  // 引数で受け取ったXmlElementクラスの参照を介して各パラメータのIDと値のペアをXMLフォーマットで書き込む。
  xml.setAttribute(OscWaveType->paramID, OscWaveType->getIndex());
  xml.setAttribute(VolumeLevel->paramID, (double)VolumeLevel->get());
  xml.setAttribute(Attack->paramID, (double)Attack->get());
  xml.setAttribute(Decay->paramID, (double)Decay->get());
  xml.setAttribute(Sustain->paramID, (double)Sustain->get());
  xml.setAttribute(Release->paramID, (double)Release->get());
  xml.setAttribute(ColorType->paramID, ColorType->getIndex());
  xml.setAttribute(ColorDuration->paramID, (double)ColorDuration->get());
}

void ChipOscillatorParameters::loadParameters(XmlElement& xml) {
  // 引数で受け取ったXmlElementクラスの参照を介してXMLフォーマットのデータから各パラメータに対応する値を読み込んで代入する。
  *OscWaveType = xml.getIntAttribute(OscWaveType->paramID, 0);
  *VolumeLevel = (float)xml.getDoubleAttribute(VolumeLevel->paramID, 1.0);
  *Attack = (float)xml.getDoubleAttribute(Attack->paramID, 0.01);
  *Decay = (float)xml.getDoubleAttribute(Decay->paramID, 0.01);
  *Sustain = (float)xml.getDoubleAttribute(Sustain->paramID, 1.0);
  *Release = (float)xml.getDoubleAttribute(Release->paramID, 0.01);
  *ColorType = xml.getIntAttribute(ColorType->paramID, 0);
  *ColorDuration = (float)xml.getDoubleAttribute(ColorDuration->paramID, 0.01);
}

//-----------------------------------------------------------------------------------------

SweepParameters::SweepParameters(AudioParameterChoice* sweepSwitch,
                                 AudioParameterFloat* sweepTime)
    : SweepSwitch(sweepSwitch), SweepTime(sweepTime) {}

void SweepParameters::addAllParameters(AudioProcessor& processor) {
  processor.addParameter(SweepSwitch);
  processor.addParameter(SweepTime);
}

void SweepParameters::saveParameters(XmlElement& xml) {
  xml.setAttribute(SweepSwitch->paramID, SweepSwitch->getIndex());
  xml.setAttribute(SweepTime->paramID, (double)SweepTime->get());
}

void SweepParameters::loadParameters(XmlElement& xml) {
  *SweepSwitch = xml.getIntAttribute(SweepSwitch->paramID, 0);
  *SweepTime = (float)xml.getDoubleAttribute(SweepTime->paramID, 1.0);
}

//-----------------------------------------------------------------------------------------

VibratoParameters::VibratoParameters(
    AudioParameterBool* vibratoEnable,
    AudioParameterBool* vibratoAttackDeleySwitch,
    AudioParameterFloat* vibratoAmount, AudioParameterFloat* vibratoSpeed,
    AudioParameterFloat* vibratoAttackTime)
    : VibratoEnable(vibratoEnable),
      VibratoAttackDeleySwitch(vibratoAttackDeleySwitch),
      VibratoAmount(vibratoAmount),
      VibratoSpeed(vibratoSpeed),
      VibratoAttackTime(vibratoAttackTime) {}

void VibratoParameters::addAllParameters(AudioProcessor& processor) {
  processor.addParameter(VibratoEnable);
  processor.addParameter(VibratoAttackDeleySwitch);
  processor.addParameter(VibratoAmount);
  processor.addParameter(VibratoSpeed);
  processor.addParameter(VibratoAttackTime);
}

void VibratoParameters::saveParameters(XmlElement& xml) {
  xml.setAttribute(VibratoEnable->paramID, VibratoEnable->get());
  xml.setAttribute(VibratoAttackDeleySwitch->paramID,
                   VibratoAttackDeleySwitch->get());
  xml.setAttribute(VibratoAmount->paramID, (double)VibratoAmount->get());
  xml.setAttribute(VibratoSpeed->paramID, (double)VibratoSpeed->get());
  xml.setAttribute(VibratoAttackTime->paramID,
                   (double)VibratoAttackTime->get());
}

void VibratoParameters::loadParameters(XmlElement& xml) {
  *VibratoEnable = (bool)xml.getBoolAttribute(VibratoEnable->paramID, true);
  *VibratoAttackDeleySwitch =
      (bool)xml.getBoolAttribute(VibratoAttackDeleySwitch->paramID, true);
  *VibratoAmount = (float)xml.getDoubleAttribute(VibratoAmount->paramID, 0.3);
  *VibratoSpeed = (float)xml.getDoubleAttribute(VibratoSpeed->paramID, 2.0);
  *VibratoAttackTime =
      (float)xml.getDoubleAttribute(VibratoAttackTime->paramID, 0.0);
}

//-----------------------------------------------------------------------------------------

VoicingParameters::VoicingParameters(AudioParameterChoice* voicingSwitch,
                                     AudioParameterFloat* stepTime)
    : VoicingSwitch(voicingSwitch), StepTime(stepTime) {}

void VoicingParameters::addAllParameters(AudioProcessor& processor) {
  processor.addParameter(VoicingSwitch);
  processor.addParameter(StepTime);
}

void VoicingParameters::saveParameters(XmlElement& xml) {
  xml.setAttribute(VoicingSwitch->paramID, VoicingSwitch->getIndex());
  xml.setAttribute(StepTime->paramID, StepTime->get());
}

void VoicingParameters::loadParameters(XmlElement& xml) {
  *VoicingSwitch = xml.getIntAttribute(VoicingSwitch->paramID, 0);
  *StepTime = (float)xml.getDoubleAttribute(StepTime->paramID, 1.0);
}

//-----------------------------------------------------------------------------------------

OptionsParameters::OptionsParameters(AudioParameterInt* pitchBendRange,
                                     AudioParameterInt* pitchStandard)
    : PitchBendRange(pitchBendRange), PitchStandard(pitchStandard) {}

void OptionsParameters::addAllParameters(AudioProcessor& processor) {
  processor.addParameter(PitchBendRange);
  processor.addParameter(PitchStandard);
}

void OptionsParameters::saveParameters(XmlElement& xml) {
  xml.setAttribute(PitchBendRange->paramID, (double)PitchBendRange->get());
  xml.setAttribute(PitchStandard->paramID, (double)PitchStandard->get());
}

void OptionsParameters::loadParameters(XmlElement& xml) {
  *PitchBendRange = xml.getIntAttribute(PitchBendRange->paramID, 2);
  *PitchStandard = xml.getIntAttribute(PitchStandard->paramID, 440);
}

//-----------------------------------------------------------------------------------------

WaveformMemoryParameters::WaveformMemoryParameters() {
  for (auto i = 0; i < WAVESAMPLE_LENGTH; ++i) {
    std::string name = "w" + std::to_string(i);
    WaveSamplesArray[i] = new AudioParameterInt(name, name, 0, 31, 0);
  }
}

void WaveformMemoryParameters::addAllParameters(AudioProcessor& processor) {
  for (auto i = 0; i < WAVESAMPLE_LENGTH; ++i) {
    processor.addParameter(WaveSamplesArray[i]);
  }
}

void WaveformMemoryParameters::saveParameters(XmlElement& xml) {
  for (auto i = 0; i < WAVESAMPLE_LENGTH; ++i) {
    xml.setAttribute(WaveSamplesArray[i]->paramID,
                     (std::int32_t)WaveSamplesArray[i]->get());
  }
}

void WaveformMemoryParameters::loadParameters(XmlElement& xml) {
  for (auto i = 0; i < WAVESAMPLE_LENGTH; ++i) {
    *WaveSamplesArray[i] = xml.getIntAttribute(WaveSamplesArray[i]->paramID, 0);
  }
}

//-----------------------------------------------------------------------------------------

MidiEchoParameters::MidiEchoParameters(AudioParameterBool* isEchoEnable,
                                       AudioParameterFloat* echoDuration,
                                       AudioParameterInt* echoRepeat,
                                       AudioParameterFloat* volumeOffset)
    : IsEchoEnable(isEchoEnable),
      EchoDuration(echoDuration),
      EchoRepeat(echoRepeat),
      VolumeOffset(volumeOffset) {}

void MidiEchoParameters::addAllParameters(AudioProcessor& processor) {
  processor.addParameter(IsEchoEnable);
  processor.addParameter(EchoDuration);
  processor.addParameter(EchoRepeat);
  processor.addParameter(VolumeOffset);
}

void MidiEchoParameters::saveParameters(XmlElement& xml) {
  xml.setAttribute(IsEchoEnable->paramID, IsEchoEnable->get());
  xml.setAttribute(EchoDuration->paramID, (double)EchoDuration->get());
  xml.setAttribute(EchoRepeat->paramID, EchoRepeat->get());
  xml.setAttribute(VolumeOffset->paramID, (double)VolumeOffset->get());
}

void MidiEchoParameters::loadParameters(XmlElement& xml) {
  *IsEchoEnable = xml.getBoolAttribute(IsEchoEnable->paramID, true);
  *EchoDuration = (float)xml.getDoubleAttribute(EchoDuration->paramID, 0.25);
  *EchoRepeat = xml.getIntAttribute(EchoRepeat->paramID, 1);
  *VolumeOffset = (float)xml.getDoubleAttribute(VolumeOffset->paramID, 50);
}

//-----------------------------------------------------------------------------------------

FilterParameters::FilterParameters(AudioParameterBool* hicutEnable,
                                   AudioParameterBool* lowcutEnable,
                                   AudioParameterFloat* hicutFreq,
                                   AudioParameterFloat* lowcutFreq)
    : HicutEnable(hicutEnable),
      LowcutEnable(lowcutEnable),
      HicutFreq(hicutFreq),
      LowcutFreq(lowcutFreq) {}

void FilterParameters::addAllParameters(AudioProcessor& processor) {
  processor.addParameter(HicutEnable);
  processor.addParameter(LowcutEnable);
  processor.addParameter(HicutFreq);
  processor.addParameter(LowcutFreq);
}

void FilterParameters::saveParameters(XmlElement& xml) {
  xml.setAttribute(HicutEnable->paramID, HicutEnable->get());
  xml.setAttribute(LowcutEnable->paramID, LowcutEnable->get());
  xml.setAttribute(HicutFreq->paramID, HicutFreq->get());
  xml.setAttribute(LowcutFreq->paramID, LowcutFreq->get());
}

void FilterParameters::loadParameters(XmlElement& xml) {
  *HicutEnable = xml.getBoolAttribute(HicutEnable->paramID, false);
  *LowcutEnable = xml.getBoolAttribute(LowcutEnable->paramID, false);
  *HicutFreq = (float)xml.getDoubleAttribute(HicutFreq->paramID, 20000.0f);
  *LowcutFreq = (float)xml.getDoubleAttribute(LowcutFreq->paramID, 20.0f);
}

//-----------------------------------------------------------------------------------------

PresetsParameters::PresetsParameters() {
  ProgramIndex = new AudioParameterInt("PROGRAM_INDEX", "Program-Index", 0, NUM_OF_PRESETS, 0);
}

void PresetsParameters::addAllParameters(AudioProcessor& processor) {
  processor.addParameter(ProgramIndex);
}

void PresetsParameters::saveParameters(XmlElement& xml) {
  xml.setAttribute(ProgramIndex->paramID, ProgramIndex->get());
}

void PresetsParameters::loadParameters(XmlElement& xml) {
  *ProgramIndex = xml.getIntAttribute(ProgramIndex->paramID, 0);
}

//-----------------------------------------------------------------------------------------

WavePatternParameters::WavePatternParameters() {
  for (auto i = 0; i < WAVEPATTERN_LENGTH; ++i) {
    std::string name = "WavePattern" + std::to_string(i);
    WavePatternArray[i] = new AudioParameterInt(name, name, 0, 7, 0);
  }

  for (auto i = 0; i < WAVEPATTERN_TYPES; ++i) {
    std::string name = "WavePatternType" + std::to_string(i);
    WaveTypes[i] = new AudioParameterChoice(name, name, OSC_WAVE_TYPES, 0);
  }

  PatternEnabled = new AudioParameterBool("PATTERN_ENABLE", "Pattern-Enable", false);
  LoopEnabled = new AudioParameterBool("PATTERN_LOOP_ENABLE", "Pattern-Loop-Enable", true);
  StepTime = new AudioParameterFloat("PATTERN_STEP_TIME", "Pattern-Step-Time", {0.000f, 1.0f, MIN_DELTA}, 0.10f);
}

void WavePatternParameters::addAllParameters(AudioProcessor& processor) {
  for (auto i = 0; i < WAVEPATTERN_LENGTH; ++i) {
    processor.addParameter(WavePatternArray[i]);
  }
  for (auto i = 0; i < WAVEPATTERN_TYPES; ++i) {
    processor.addParameter(WaveTypes[i]);
  }
  processor.addParameter(PatternEnabled);
  processor.addParameter(LoopEnabled);
  processor.addParameter(StepTime);
}

void WavePatternParameters::saveParameters(XmlElement& xml) {
  for (auto i = 0; i < WAVEPATTERN_LENGTH; ++i) {
    xml.setAttribute(WavePatternArray[i]->paramID, (std::int32_t)WavePatternArray[i]->get());
  }
  for (auto i = 0; i < WAVEPATTERN_TYPES; ++i) {
    xml.setAttribute(WaveTypes[i]->paramID, (std::int32_t)WaveTypes[i]->getIndex());
  }
  xml.setAttribute(PatternEnabled->paramID, (double)PatternEnabled->get());
  xml.setAttribute(LoopEnabled->paramID, (double)LoopEnabled->get());
  xml.setAttribute(StepTime->paramID, (double)StepTime->get());
}

void WavePatternParameters::loadParameters(XmlElement& xml) {
  for (auto i = 0; i < WAVEPATTERN_LENGTH; ++i) {
    *WavePatternArray[i] = xml.getIntAttribute(WavePatternArray[i]->paramID, 0);
  }
  for (auto i = 0; i < WAVEPATTERN_TYPES; ++i) {
    *WaveTypes[i] = xml.getIntAttribute(WaveTypes[i]->paramID, 0);
  }
  *PatternEnabled = xml.getBoolAttribute(PatternEnabled->paramID, false);
  *LoopEnabled = xml.getBoolAttribute(LoopEnabled->paramID, true);
  *StepTime = xml.getDoubleAttribute(StepTime->paramID, 0.10f);
}

//-----------------------------------------------------------------------------------------