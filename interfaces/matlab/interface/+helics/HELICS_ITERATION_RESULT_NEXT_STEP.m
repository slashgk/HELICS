function v = HELICS_ITERATION_RESULT_NEXT_STEP()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = helicsMEX(0, 126);
  end
  v = vInitialized;
end