using HiGHS
using JuMP


mutable struct ArestasGrafo
    n::Int
    Arestas::Array{Array{Int}} 
end

function readData(file)
	n = 0
	Arestas = []
	for l in eachline(file)
		q = split(l, "\t")

		if q[1] == "n"
			n = parse(Int, q[2])

		elseif q[1] == "e"
			v = parse(Int64, q[2])
			u = parse(Int64, q[3])
            push!(Arestas,[v,u])
		end
	end
	return ArestasGrafo(n,Arestas)
end

function printSolution(data,x,c)
    k = 1
    for j=1:data.n
        if (round(value(c[j]))) == 1
            print("COR $k: ")
            k = k + 1
            for i=1:data.n
                if (round(value(x[i,j])) ) == 1
                    print("$i ")
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

@variable(model, c[i=1:data.n], Bin)
@variable(model, x[i=1:data.n,j=1:data.n], Bin)


for i=1:(size(data.Arestas)[1])
    for j=1:data.n
        @constraint(model, x[data.Arestas[i][1],j] + x[data.Arestas[i][2],j] <= 1 * c[j])	
    end
end
for i=1:data.n
    @constraint(model,sum(x[i,j] for j=1:data.n) == 1)	
end

@objective(model, Min, sum(c[i] for i=1:data.n))

#print(model)

optimize!(model)

sol = objective_value(model)
println("TP1 2022043663 = ", sol)

#printSolution(data, x, c)