/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.1
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.java.helics;

/**
 *  single character data type  this is intentionally the same as string enumeration of possible federate flags
 */
public final class HelicsFederateFlags {
  /**
   *  flag indicating that a federate is observe only
   */
  public final static HelicsFederateFlags HELICS_FLAG_OBSERVER = new HelicsFederateFlags("HELICS_FLAG_OBSERVER", helicsJNI.HELICS_FLAG_OBSERVER_get());
  /**
   *  flag indicating that a federate can only return requested times
   */
  public final static HelicsFederateFlags HELICS_FLAG_UNINTERRUPTIBLE = new HelicsFederateFlags("HELICS_FLAG_UNINTERRUPTIBLE", helicsJNI.HELICS_FLAG_UNINTERRUPTIBLE_get());
  /**
   *  flag indicating that a federate can be interrupted
   */
  public final static HelicsFederateFlags HELICS_FLAG_INTERRUPTIBLE = new HelicsFederateFlags("HELICS_FLAG_INTERRUPTIBLE", helicsJNI.HELICS_FLAG_INTERRUPTIBLE_get());
  /**
   *  flag indicating that a federate/interface is a signal generator only
   */
  public final static HelicsFederateFlags HELICS_FLAG_SOURCE_ONLY = new HelicsFederateFlags("HELICS_FLAG_SOURCE_ONLY", helicsJNI.HELICS_FLAG_SOURCE_ONLY_get());
  /**
   *  flag indicating a federate/interface should only transmit values if they have changed(binary<br>
   *            equivalence)
   */
  public final static HelicsFederateFlags HELICS_FLAG_ONLY_TRANSMIT_ON_CHANGE = new HelicsFederateFlags("HELICS_FLAG_ONLY_TRANSMIT_ON_CHANGE", helicsJNI.HELICS_FLAG_ONLY_TRANSMIT_ON_CHANGE_get());
  /**
   *  flag indicating a federate/interface should only trigger an update if a value has changed<br>
   * (binary equivalence)
   */
  public final static HelicsFederateFlags HELICS_FLAG_ONLY_UPDATE_ON_CHANGE = new HelicsFederateFlags("HELICS_FLAG_ONLY_UPDATE_ON_CHANGE", helicsJNI.HELICS_FLAG_ONLY_UPDATE_ON_CHANGE_get());
  /**
   *  flag indicating a federate should only grant time if all other federates have already passed<br>
   * the requested time
   */
  public final static HelicsFederateFlags HELICS_FLAG_WAIT_FOR_CURRENT_TIME_UPDATE = new HelicsFederateFlags("HELICS_FLAG_WAIT_FOR_CURRENT_TIME_UPDATE", helicsJNI.HELICS_FLAG_WAIT_FOR_CURRENT_TIME_UPDATE_get());
  /**
   *  flag indicating a federate should operate on a restrictive time policy, which disallows some<br>
   *        2nd order time evaluation and can be useful for certain types of dependency cycles<br>
   *         and update patterns, but generally shouldn't be used as it can lead to some very slow update<br>
   *        conditions
   */
  public final static HelicsFederateFlags HELICS_FLAG_RESTRICTIVE_TIME_POLICY = new HelicsFederateFlags("HELICS_FLAG_RESTRICTIVE_TIME_POLICY", helicsJNI.HELICS_FLAG_RESTRICTIVE_TIME_POLICY_get());
  /**
   *  flag indicating that a federate has rollback capability
   */
  public final static HelicsFederateFlags HELICS_FLAG_ROLLBACK = new HelicsFederateFlags("HELICS_FLAG_ROLLBACK", helicsJNI.HELICS_FLAG_ROLLBACK_get());
  /**
   *  flag indicating that a federate performs forward computation and does internal rollback
   */
  public final static HelicsFederateFlags HELICS_FLAG_FORWARD_COMPUTE = new HelicsFederateFlags("HELICS_FLAG_FORWARD_COMPUTE", helicsJNI.HELICS_FLAG_FORWARD_COMPUTE_get());
  /**
   *  flag indicating that a federate needs to run in real time
   */
  public final static HelicsFederateFlags HELICS_FLAG_REALTIME = new HelicsFederateFlags("HELICS_FLAG_REALTIME", helicsJNI.HELICS_FLAG_REALTIME_get());
  /**
   *  flag indicating that the federate will only interact on a single thread
   */
  public final static HelicsFederateFlags HELICS_FLAG_SINGLE_THREAD_FEDERATE = new HelicsFederateFlags("HELICS_FLAG_SINGLE_THREAD_FEDERATE", helicsJNI.HELICS_FLAG_SINGLE_THREAD_FEDERATE_get());
  /**
   *  used to not display warnings on mismatched requested times
   */
  public final static HelicsFederateFlags HELICS_FLAG_IGNORE_TIME_MISMATCH_WARNINGS = new HelicsFederateFlags("HELICS_FLAG_IGNORE_TIME_MISMATCH_WARNINGS", helicsJNI.HELICS_FLAG_IGNORE_TIME_MISMATCH_WARNINGS_get());
  /**
   *  specify that checking on configuration files should be strict and throw and error on any<br>
   *    invalid values 
   */
  public final static HelicsFederateFlags HELICS_FLAG_STRICT_CONFIG_CHECKING = new HelicsFederateFlags("HELICS_FLAG_STRICT_CONFIG_CHECKING", helicsJNI.HELICS_FLAG_STRICT_CONFIG_CHECKING_get());
  /**
   *  specify that the federate is event triggered-meaning (all/most) events are triggered by<br>
   *        incoming events
   */
  public final static HelicsFederateFlags HELICS_FLAG_EVENT_TRIGGERED = new HelicsFederateFlags("HELICS_FLAG_EVENT_TRIGGERED", helicsJNI.HELICS_FLAG_EVENT_TRIGGERED_get());
  /**
   *  specify that that federate should capture the profiling data to the local federate logging<br>
   *        system
   */
  public final static HelicsFederateFlags HELICS_FLAG_LOCAL_PROFILING_CAPTURE = new HelicsFederateFlags("HELICS_FLAG_LOCAL_PROFILING_CAPTURE", helicsJNI.HELICS_FLAG_LOCAL_PROFILING_CAPTURE_get());

  public final int swigValue() {
    return swigValue;
  }

  public String toString() {
    return swigName;
  }

  public static HelicsFederateFlags swigToEnum(int swigValue) {
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (int i = 0; i < swigValues.length; i++)
      if (swigValues[i].swigValue == swigValue)
        return swigValues[i];
    throw new IllegalArgumentException("No enum " + HelicsFederateFlags.class + " with value " + swigValue);
  }

  private HelicsFederateFlags(String swigName) {
    this.swigName = swigName;
    this.swigValue = swigNext++;
  }

  private HelicsFederateFlags(String swigName, int swigValue) {
    this.swigName = swigName;
    this.swigValue = swigValue;
    swigNext = swigValue+1;
  }

  private HelicsFederateFlags(String swigName, HelicsFederateFlags swigEnum) {
    this.swigName = swigName;
    this.swigValue = swigEnum.swigValue;
    swigNext = this.swigValue+1;
  }

  private static HelicsFederateFlags[] swigValues = { HELICS_FLAG_OBSERVER, HELICS_FLAG_UNINTERRUPTIBLE, HELICS_FLAG_INTERRUPTIBLE, HELICS_FLAG_SOURCE_ONLY, HELICS_FLAG_ONLY_TRANSMIT_ON_CHANGE, HELICS_FLAG_ONLY_UPDATE_ON_CHANGE, HELICS_FLAG_WAIT_FOR_CURRENT_TIME_UPDATE, HELICS_FLAG_RESTRICTIVE_TIME_POLICY, HELICS_FLAG_ROLLBACK, HELICS_FLAG_FORWARD_COMPUTE, HELICS_FLAG_REALTIME, HELICS_FLAG_SINGLE_THREAD_FEDERATE, HELICS_FLAG_IGNORE_TIME_MISMATCH_WARNINGS, HELICS_FLAG_STRICT_CONFIG_CHECKING, HELICS_FLAG_EVENT_TRIGGERED, HELICS_FLAG_LOCAL_PROFILING_CAPTURE };
  private static int swigNext = 0;
  private final int swigValue;
  private final String swigName;
}

