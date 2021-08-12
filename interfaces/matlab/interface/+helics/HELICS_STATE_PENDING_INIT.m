function v = HELICS_STATE_PENDING_INIT()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = helicsMEX(0, 135);
  end
  v = vInitialized;
end