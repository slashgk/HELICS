function v = HELICS_HANDLE_OPTION_MULTI_INPUT_HANDLING_METHOD()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = helicsMEX(0, 110);
  end
  v = vInitialized;
end