function v = HELICS_FILTER_TYPE_DELAY()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = helicsMEX(0, 115);
  end
  v = vInitialized;
end
