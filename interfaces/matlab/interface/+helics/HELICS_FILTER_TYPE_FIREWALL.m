function v = HELICS_FILTER_TYPE_FIREWALL()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = helicsMEX(0, 120);
  end
  v = vInitialized;
end