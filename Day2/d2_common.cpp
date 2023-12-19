#include <d2_common.h>

Game Game::parseLine(const std::string& input_line)
{
    std::vector<std::pair<int, char> >* input = parseInput(input_line);
    std::vector<round> rounds;
    int game_id = input->at(0).first;
    round current_round(-1, -1, -1);
    for(int i = 1; i < input->size(); ++i)
    {
        int* comp;
        switch(input->at(i).second)
        {
            case 'r':
                comp = &current_round.d_r;
                break;
            case 'g':
                comp = &current_round.d_g;
                break;
            case 'b':
                comp = &current_round.d_b;
                break;
        }
        if(*comp != -1)
        {
            // new round
            current_round.d_r = std::max(current_round.d_r, 0);
            current_round.d_g = std::max(current_round.d_g, 0);
            current_round.d_b = std::max(current_round.d_b, 0);
            rounds.push_back(current_round);
            current_round.d_r = current_round.d_g = current_round.d_b = -1;
        }
        *comp = input->at(i).first;
    }
    // last round
    current_round.d_r = std::max(current_round.d_r, 0);
    current_round.d_g = std::max(current_round.d_g, 0);
    current_round.d_b = std::max(current_round.d_b, 0);
    rounds.push_back(current_round);

    delete input;
    return Game(game_id, rounds);
}

std::vector<std::pair<int, char> >* Game::parseInput(const std::string& line)
{
    std::vector<std::string>* tokens = tokenize(line, ' ');
    std::vector<std::pair<int, char> >* ret = new std::vector<std::pair<int, char> >();
    int game_id = std::stoi(tokens->at(1));
    ret->push_back(std::make_pair(game_id, '#'));
    for(int i=2; i < tokens->size(); i += 2)
    {
        int cnt = std::stoi(tokens->at(i));
        char c = tokens->at(i+1)[0];
        if(c != 'r' && c != 'g' && c != 'b')
        {
            throw std::runtime_error("Invalid color code: " + c);
        }
        ret->push_back(std::make_pair(cnt, c));
    }
    delete tokens;
    return ret;
}

std::vector<std::string>* tokenize(const  std::string& s, const char& delimiter)
{
    std::vector<std::string>* ret = new std::vector<std::string>();
    std::string token;
    for(int i=0; i <= s.size(); ++i)
    {
        if(i < s.size() && s[i] != delimiter)
        {
            token += s[i];
        }
        else
        {
            if(token != "")
            {
                ret -> push_back(token);
                token = "";
            }
        }
    }
    return ret;
}

Game::Game(int id, const std::vector<round>& rounds) :
    d_id{id}, d_rounds{rounds}
{

}

std::vector<Game> read_input()
{
    std::vector<Game> ret;
    std::string input_line;
    while(std::getline(std::cin, input_line))
    {
        ret.push_back(Game::parseLine(input_line));
    }
    return ret;
}

const std::vector<Game::round>& Game::rounds() const
{
    return d_rounds;
}

const int Game::id() const
{
    return d_id;
}
