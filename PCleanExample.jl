# This is a simple example program I wrote in PClean, a data-cleaning probabilistic programming language.
# In the load_data.jl file, there is a "clean" and a "dirty" data set, where the "dirty" set may have mistakes, missing cells, or typos.
# This code uses PClean's inference techniques to try to fix the "dirty" data set, and then it uses the evaluate_accuracy function to compare the fixed table to the correct clean table
# One other thing we did was modify the AddTypos function so that it can depend on a language model like GPT-Neo.

using PClean

include("load_data.jl")

PClean.@model Animodel begin

  @class Obs begin
    @learned avg_weight::Dict{String, MeanParameter{400.0}}
    atype ~ ChooseUniformly(animal_types)
    weight_base = avg_weight["$(atype)"]
    weight ~ AddNoise(weight_base, 10.0)
    dirty_atype ~ AddTypos(atype,2)
  end;
end;

query = @query Animodel.Obs [
  "animal" atype dirty_atype
  "weight" weight
];

config = PClean.InferenceConfig(1, 2; use_mh_instead_of_pg=true, rejuv_frequency=10)
observations = [ObservedDataset(query, dirty_table)]
# println(observations)

@time begin
  trace = initialize_trace(observations, config);
  run_inference!(trace, config);
end

results = evaluate_accuracy(dirty_table, clean_table, trace.tables[:Obs], query)
PClean.save_results("results", "testcats", trace, observations)
println(results)
