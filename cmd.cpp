Cmd::Cmd(int argc, char *argv[])
{
    filename = argv[1];
}

Cmd::~Cmd()
{

}

Cmd::getFileName()
{
    return filename;
}
