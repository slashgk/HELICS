function v = helics_data_type_time()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = helicsMEX(0, 20);
  end
  v = vInitialized;
end