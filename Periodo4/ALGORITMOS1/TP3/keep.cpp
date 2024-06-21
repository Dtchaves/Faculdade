    cout<<endl<<"N_secoes "<<N_secoes<<endl<<"N_manobras "<<N_manobras<<endl;

    for(i = 0; i<N_secoes;i++){
        cout<<"Secao "<<i<<endl<<"Bonificacao "<<pista[i].bonificacao<<endl<<"Tempo "<<pista[i].tempo<<endl;
    }

    for(i = 0; i<N_manobras;i++){
        cout<<"Manobra "<<i<<endl<<"Pontuacao "<<manobras[i].pontuacao<<endl<<"Tempo "<<manobras[i].tempo<<endl;
    }

    for(i = 0; i<N_secoes;i++){
        vector<int> Manobras_feitas;
        int tamanho = 0;
        int safe = resultado.manobras[i];
        for(n_bit = 0; n_bit < N_manobras;n_bit++){
            bit = (safe & 1);
            safe = safe >> 1;
            if(bit){
                Manobras_feitas.push_back(i+1);
                tamanho++;
            }
        }
        cout<<tamanho;
        for(j = 0;j<Manobras_feitas.size();j++){
            cout<<" "<<Manobras_feitas[j];
        }
        cout<<endl;
    }