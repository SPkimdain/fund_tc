import os
from langchain.agents import AgentExecutor, create_tool_calling_agent, tool
from langchain_openai import ChatOpenAI
from langchain_core.prompts import ChatPromptTemplate, MessagesPlaceholder
from django.http import HttpRequest
from ldap3 import Connection, Server, ALL

@tool
def tell_joke(content: str) -> str:
    return f"{content}"

tools = [tell_joke]
system_prompt = "prompt"
prompt = ChatPromptTemplate.from_messages([
    ("system", system_prompt),
    ("human", "{input}"),
    MessagesPlaceholder(variable_name="agent_scratchpad")
])

def process_unsafe_request(request: HttpRequest):
    model = ChatOpenAI(openai_api_key=os.environ.get("OPENAI_API_KEY"))
    agent = create_tool_calling_agent(model, tools, prompt)
    agent_executor = AgentExecutor(agent=agent, tools=tools, verbose=True)

    user_input = request.POST.get('user_query')

    agent_executor.invoke(user_input) # @violation
