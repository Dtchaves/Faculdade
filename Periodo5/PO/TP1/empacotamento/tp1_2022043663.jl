using HiGHS
using JuMP


mutable struct EmpacotamentoData
    n::Int
    objw::Array{Float64} 
end

function readData(file)
	n = 0
	objw = Vector{Float64}(undef, n) 

    for l in eachline(file)
        q = split(l, "\t")

        if q[1] == "n"
            n = parse(Int64, q[2])
            objw = zeros(Float64, n)
        elseif q[1] == "o"
            i = parse(Int64, q[2]) + 1
            w = parse(Float64, q[3])  
            objw[i] = w
		end
	end
	return EmpacotamentoData(n,objw)
end

function printSolution(data,x,y)
    k = 1
    for j=1:data.n
        if (round(value(y[j]))) == 1
            print("CAIXA $k: ")
            k = k + 1
            for i=1:data.n
                if (round(value(x[i,j])) ) == 1
                    print("$(i-1) ")
                end
            end
            print("\n")
        end
    end
end

model = Model(HiGHS.Optimizer)

set_silent(model)


file = open(ARGS[1], "r")

data = readData(file)

@variable(model, x[i=1:data.n, j=1:data.n], Bin)
@variable(model, y[j=1:data.n], Bin)


for j=1:data.n
	@constraint(model, sum(x[i,j] * data.objw[i] for i=1:data.n) <= 20*y[j])	
end

for i=1:data.n
	@constraint(model, sum(x[i,j] for j=1:data.n) == 1)	
end


@objective(model, Min, sum(y[j] for j=1:data.n))

#print(model)

optimize!(model)

sol = objective_value(model)

println("TP1 2022043663 = ", sol)

#printSolution(data, x, y)

