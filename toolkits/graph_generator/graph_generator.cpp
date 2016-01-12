#include <graphlab.hpp>

typedef graphlab::empty vertex_data_type;
typedef graphlab::empty edge_data_type;
typedef graphlab::distributed_graph<vertex_data_type, edge_data_type> graph_type;

int main(int argc, char** argv){
  graphlab::distributed_control dc;
  graphlab::command_line_options clopts("Graph generator");
  graph_type graph(dc, clopts);
  double alpha = argc >= 3 ? atof(argv[2]) : 2.1;
  graph.write_synthetic_powerlaw(atol(argv[1]), false, alpha, 100000000);
}
