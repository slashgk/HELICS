function v = HELICS_STATE_PENDING_EXEC()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = helicsMEX(0, 136);
  end
  v = vInitialized;
end