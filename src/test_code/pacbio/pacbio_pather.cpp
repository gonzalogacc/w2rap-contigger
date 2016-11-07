//
// Created by Gonzalo Garcia (TGAC) on 04/11/2016.
//

#include "pacbio_pather.h"

std::vector<int> PacbioPather::MapReads(vecbvec seqVector, HyperBasevector* hbv){
  // get the reads and map them to the graph using the dictionary
  // returns a vector of paths
  auto edges = hbv->Edges();
  vec<int> inv;
  hbv->Involution(inv);

  int cont = 0;
  for (auto v=0; v<seqVector.size(); ++v){
//  for (auto v=0; v<5; ++v){
    std::vector<int> s;
    auto g = this->lookupRead(seqVector[v].ToString());

    if (g.size()>10){
      for (auto a=0; a<g.size(); ++a){
        s.push_back(g[a].edge_id);
//        std::cout << "Read: " << cont << " mapped "<< this->lookupRead(seqVector[v].ToString()).size() << " places*kmers"  << std::endl;
//        std::cout<< cont << " " << g[a].edge_id << " " << inv[g[a].edge_id] << " " << g[a].offset<< " " << g[a].kmer << std::endl;
      }
      std::set<int> ss(s.begin(), s.end());
      std::cout << "Read mapped: " << seqVector[v] << std::endl;
      if (ss.size()>1){
        for (auto x: ss){
          std::cout << "Edge index: " << x << " " << inv[x] << std::endl;
          //        std::cout << edges[x] << std::endl;

        }
      }

    }
    cont ++;
  }
  std::cout << "mapped reads: " << cont << std::endl;
}