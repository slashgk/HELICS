function v = helics_error_external_type()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = helicsMEX(0, 62);
  end
  v = vInitialized;
end
