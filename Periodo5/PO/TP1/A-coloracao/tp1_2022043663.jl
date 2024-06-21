using HiGHS
using JuMP

mutable struct Acolour
    n::Int #numero de vertices
    ng::Array{Array{Int}} #vizinhancas
end

function readData(file)
    n = 0
    ng = [[]]
    for l in eachline(file)
        q = split(l, "\t")

        if q[1] == "n"
            n = parse(Int, q[2])
            ng = [[] for i=1:n]
        elseif q[1] == "e"
            v = parse(Int64, q[2])
            u = parse(Int64, q[3])
            push!(ng[v], u)
            push!(ng[u], v)
        end
    end
    for i=1:n
        sort(ng[i])
    end
    
    return Acolour(n,ng)
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
@variable(model, x[u=1:data.n,v=1:data.n,i=1:data.n,j=1:data.n], Bin)
@variable(model, y[u=1:data.n,i=1:data.n], Bin)

for u=1:data.n
    for v in data.ng[u]
        for i=1:data.n
            #Dois vértices da mesma cor não podem ter arestas
            @constraint(model, y[u,i] + y[v,i] <= c[i])	
        end
    end
end

for i=1:data.n
    for j=i+1:data.n
        for u=1:data.n
            for v in data.ng[u]
                #Só podemos ter 1 na matriz caso ambos tenham as cores correspondentes
                @constraint(model, x[u,v,i,j] <= y[u,i])
                @constraint(model, x[u,v,i,j] <= y[v,j])
            end
        end
        #Se tem cor i e j então temos que ter aresta entre elas
        @constraint(model,sum(x[u,v,i,j] for u=1:data.n, v in data.ng[u]) >= c[j] + c[i] - 1)
    end
    #Cada vértice tem exatamente uma cor
    @constraint(model,sum(y[i,j] for j=1:data.n) == 1)	
end

@objective(model, Max, sum(c[i] for i=1:data.n))

#print(model)

optimize!(model)

sol = objective_value(model)
println("TP1 2022043663 = ", sol)

#printSolution(data, x, c)