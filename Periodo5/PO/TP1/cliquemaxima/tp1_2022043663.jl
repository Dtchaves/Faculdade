using HiGHS
using JuMP


mutable struct MatrizAdj
    n::Int
    Matriz::Array{Array{Bool}} 
end

function readData(file)
	n = 0
	Matriz = Array{Array{Bool}}(undef, 0)
	for l in eachline(file)
		q = split(l, "\t")

		if q[1] == "n"
			n = parse(Int, q[2])
            for i in 1:n
                push!(Matriz, zeros(Bool, n))
            end
		elseif q[1] == "e"
			v = parse(Int64, q[2])
			u = parse(Int64, q[3])
            Matriz[u][v] = true
            Matriz[v][u] = true

		end
	end
	return MatrizAdj(n,Matriz)
end

function printSolution(data,x)
    for j=1:data.n
        if (round(value(x[j]))) == 1
            print("$j ")
        end
    end
end

model = Model(HiGHS.Optimizer)

set_silent(model)

file = open(ARGS[1], "r")

data = readData(file)

@variable(model, x[i=1:data.n], Bin)

for i=1:data.n
    for j=1:data.n
        if i != j
            @constraint(model, x[i] + x[j] <= data.Matriz[i][j]+1)	
        end
    end
end

@objective(model, Max, sum(x[i] for i=1:data.n))

#print(model)

optimize!(model)

sol = objective_value(model)

println("TP1 2022043663 = ", sol)

#printSolution(data, x)